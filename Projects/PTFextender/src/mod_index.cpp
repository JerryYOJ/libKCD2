#include "mod_index.h"

#include <windows.h>

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <cstring>

namespace ptf {
namespace {

std::string Lower(const std::string& s)
{
    std::string out(s);
    std::transform(out.begin(), out.end(), out.begin(),
                   [](unsigned char c) { return static_cast<char>(::tolower(c)); });
    return out;
}

std::string BareName(const std::string& path)
{
    const size_t slash = path.find_last_of("/\\");
    return (slash == std::string::npos) ? path : path.substr(slash + 1);
}

// ---------------------------------------------------------------- zip reading
//
// Only the central directory, and only the names. A pak is a plain zip: the End Of Central
// Directory record is the last thing in the file, and it points at a run of 0x02014b50 headers each
// carrying a name length and a name. Nothing here decompresses anything.
//
// The EOCD sits at the very end unless the archive has a trailing comment, so it is found by
// scanning backwards over the last 64 KB -- the largest a comment may be.

#pragma pack(push, 1)
struct EOCD {
    uint32_t sig;            // 0x06054b50
    uint16_t disk, cdDisk;
    uint16_t entriesHere, entriesTotal;
    uint32_t cdSize, cdOffset;
    uint16_t commentLen;
};
struct CDHeader {
    uint32_t sig;            // 0x02014b50
    uint16_t madeBy, needed, flags, method;
    uint16_t modTime, modDate;
    uint32_t crc, compSize, uncompSize;
    uint16_t nameLen, extraLen, commentLen;
    uint16_t diskStart, internalAttr;
    uint32_t externalAttr, localOffset;
};
#pragma pack(pop)

bool ReadAt(HANDLE h, long long offset, void* buf, DWORD n)
{
    LARGE_INTEGER li;
    li.QuadPart = offset;
    if (!::SetFilePointerEx(h, li, nullptr, FILE_BEGIN)) {
        return false;
    }
    DWORD got = 0;
    return ::ReadFile(h, buf, n, &got, nullptr) && got == n;
}

}  // namespace

void ModIndex::IndexPak(const std::string& pakPath, const std::string& modid)
{
    HANDLE h = ::CreateFileA(pakPath.c_str(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE,
                             nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (h == INVALID_HANDLE_VALUE) {
        return;
    }
    LARGE_INTEGER size{};
    if (!::GetFileSizeEx(h, &size) || size.QuadPart < static_cast<long long>(sizeof(EOCD))) {
        ::CloseHandle(h);
        return;
    }

    // scan back over at most 64 KB + the EOCD itself for the signature
    const long long tailLen = (std::min)(static_cast<long long>(64 * 1024 + sizeof(EOCD)),
                                         size.QuadPart);
    std::vector<unsigned char> tail(static_cast<size_t>(tailLen));
    if (!ReadAt(h, size.QuadPart - tailLen, tail.data(), static_cast<DWORD>(tailLen))) {
        ::CloseHandle(h);
        return;
    }
    long long eocdAt = -1;
    for (long long i = tailLen - static_cast<long long>(sizeof(EOCD)); i >= 0; --i) {
        uint32_t sig = 0;
        std::memcpy(&sig, tail.data() + i, sizeof(sig));
        if (sig == 0x06054b50u) {
            eocdAt = i;
            break;
        }
    }
    if (eocdAt < 0) {
        ::CloseHandle(h);
        return;
    }
    EOCD eocd{};
    std::memcpy(&eocd, tail.data() + eocdAt, sizeof(eocd));

    // ZIP64 archives put 0xFFFFFFFF here. No mod pak measured is near 4 GB, and reading a truncated
    // directory would silently under-report provenance -- which fails OPEN, letting base files
    // through. Skip the pak instead, and let the caller see it in the pak count.
    if (eocd.cdOffset == 0xFFFFFFFFu || eocd.cdSize == 0xFFFFFFFFu ||
        eocd.entriesTotal == 0xFFFFu) {
        ::CloseHandle(h);
        return;
    }

    std::vector<unsigned char> cd(eocd.cdSize);
    if (eocd.cdSize == 0 || !ReadAt(h, eocd.cdOffset, cd.data(), eocd.cdSize)) {
        ::CloseHandle(h);
        return;
    }
    ::CloseHandle(h);

    size_t at = 0;
    for (uint16_t i = 0; i < eocd.entriesTotal; ++i) {
        if (at + sizeof(CDHeader) > cd.size()) {
            break;
        }
        CDHeader hdr{};
        std::memcpy(&hdr, cd.data() + at, sizeof(hdr));
        if (hdr.sig != 0x02014b50u) {
            break;
        }
        const size_t nameAt = at + sizeof(CDHeader);
        if (nameAt + hdr.nameLen > cd.size()) {
            break;
        }
        std::string name(reinterpret_cast<const char*>(cd.data() + nameAt), hdr.nameLen);
        if (!name.empty() && name.back() != '/' && name.back() != '\\') {
            // BARE NAME, because that is what the find record carries. Two mods shipping the same
            // bare name in different directories is not a case this has to separate: eligibility
            // asks "did a mod ship a file called this", and the merge then loads it by full path.
            m_owner[Lower(BareName(name))] = modid;
        }
        at = nameAt + hdr.nameLen + hdr.extraLen + hdr.commentLen;
    }
    ++m_paks;
}

bool ModIndex::Build(const std::string& gameRoot)
{
    m_order.clear();
    m_rank.clear();
    m_owner.clear();
    m_paks = 0;

    const std::string modsDir = gameRoot + "\\Mods";
    const std::string orderPath = modsDir + "\\mod_order.txt";

    HANDLE h = ::CreateFileA(orderPath.c_str(), GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE,
                             nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (h == INVALID_HANDLE_VALUE) {
        return false;
    }
    LARGE_INTEGER size{};
    ::GetFileSizeEx(h, &size);
    std::string text;
    if (size.QuadPart > 0 && size.QuadPart < (1 << 20)) {
        text.resize(static_cast<size_t>(size.QuadPart));
        DWORD got = 0;
        ::ReadFile(h, &text[0], static_cast<DWORD>(text.size()), &got, nullptr);
        text.resize(got);
    }
    ::CloseHandle(h);

    // A BOM lands on the FIRST modid and nowhere else, so the list reads as correct while exactly
    // one mod fails to match its folder. Windows PowerShell writes one for `-Encoding utf8`, and
    // this file is hand-edited as often as it is generated.
    if (text.size() >= 3 && static_cast<unsigned char>(text[0]) == 0xEF &&
        static_cast<unsigned char>(text[1]) == 0xBB && static_cast<unsigned char>(text[2]) == 0xBF) {
        text.erase(0, 3);
    }

    size_t pos = 0;
    while (pos <= text.size()) {
        const size_t nl = text.find('\n', pos);
        std::string line = text.substr(pos, (nl == std::string::npos ? text.size() : nl) - pos);
        pos = (nl == std::string::npos) ? text.size() + 1 : nl + 1;
        while (!line.empty() && (line.back() == '\r' || line.back() == ' ' || line.back() == '\t')) {
            line.pop_back();
        }
        size_t b = 0;
        while (b < line.size() && (line[b] == ' ' || line[b] == '\t')) {
            ++b;
        }
        line = line.substr(b);
        if (line.empty() || line[0] == '#') {
            continue;
        }
        m_rank[Lower(line)] = static_cast<int>(m_order.size());
        m_order.push_back(line);
    }

    // Walk each enabled mod for its paks. A mod listed with no folder on disk simply contributes
    // nothing -- that is a real state (`temptation` is listed on this install and has no folder),
    // not an error.
    for (const std::string& modid : m_order) {
        std::vector<std::string> dirs{modsDir + "\\" + modid};
        while (!dirs.empty()) {
            const std::string dir = dirs.back();
            dirs.pop_back();
            WIN32_FIND_DATAA fd{};
            HANDLE fh = ::FindFirstFileA((dir + "\\*").c_str(), &fd);
            if (fh == INVALID_HANDLE_VALUE) {
                continue;
            }
            do {
                const std::string name = fd.cFileName;
                if (name == "." || name == "..") {
                    continue;
                }
                const std::string full = dir + "\\" + name;
                if (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                    dirs.push_back(full);
                } else if (name.size() > 4 &&
                           Lower(name.substr(name.size() - 4)) == ".pak") {
                    IndexPak(full, modid);
                }
            } while (::FindNextFileA(fh, &fd));
            ::FindClose(fh);
        }
    }
    return true;
}

int ModIndex::Rank(const std::string& modid) const
{
    const auto it = m_rank.find(Lower(modid));
    return (it == m_rank.end()) ? -1 : it->second;
}

const char* ModIndex::Owner(const std::string& fileName) const
{
    const auto it = m_owner.find(Lower(BareName(fileName)));
    return (it == m_owner.end()) ? nullptr : it->second.c_str();
}

}  // namespace ptf
