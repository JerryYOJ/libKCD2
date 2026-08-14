//////////////////////////////////////////////////////////////////////////
//
//  Crytek Engine Source File.
//  Copyright (C), Crytek Studios, 2001-2009.
// -------------------------------------------------------------------------
//  File name:   CryGUID.h
//  Version:     v1.00
//  Created:     02/25/2009 by CarstenW
//  Description: Part of CryEngine's extension framework.
// -------------------------------------------------------------------------
//
////////////////////////////////////////////////////////////////////////////

#ifndef _CRYGUID_H_
#define _CRYGUID_H_

#pragma once

#include <cstddef>
#include <functional>

struct CryGUID
{
	uint64 hipart;
	uint64 lopart;

	// !!! Do NOT turn CryGUID into a non-aggregate !!!
	// It will prevent inlining and type list unrolling opportunities within 
	// cryinterface_cast<T>() and cryiidof<T>(). As such prevent constructors,
	// non-public members, base classes and virtual functions!

	//CryGUID() : hipart(0), lopart(0) {}
	//CryGUID(uint64 h, uint64 l) : hipart(h), lopart(l) {}

	static CryGUID Construct(const uint64& hipart, const uint64& lopart)
	{
		CryGUID guid = {hipart, lopart};
		return guid;
	}

	bool operator ==(const CryGUID& rhs) const {return hipart == rhs.hipart && lopart == rhs.lopart;}
	bool operator !=(const CryGUID& rhs) const {return hipart != rhs.hipart || lopart != rhs.lopart;}
	bool operator <(const CryGUID& rhs) const {return hipart == rhs.hipart ? lopart < rhs.lopart : hipart < rhs.hipart;}
};

namespace std
{
	template <>
	struct hash<CryGUID>
	{
		std::size_t operator ()(const CryGUID& value) const noexcept
		{
			const auto fnv1a = [](const uint64& part)
			{
				std::size_t hash = 0xCBF29CE484222325ULL;
				const auto* bytes = reinterpret_cast<const unsigned char*>(&part);
				for (std::size_t i = 0; i < sizeof(part); ++i)
					hash = (hash ^ bytes[i]) * 0x100000001B3ULL;
				return hash;
			};

			return fnv1a(value.hipart) ^ fnv1a(value.lopart);
		}
	};
}


#define MAKE_CRYGUID(high, low) CryGUID::Construct((uint64) high##LL, (uint64) low##LL)


#endif // #ifndef _CRYGUID_H_
