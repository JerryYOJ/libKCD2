#include "conceptmodule/S_NodeExecuteContext.h"

namespace wh::conceptmodule {

// Local definition so hosts can stack-construct a context (the binary dtor
// 0x182650524 only releases m_source, which the _smart_ptr member already
// does). The game never virtual-calls through a caller-owned context: the
// fire pipeline constructs its own records and Execute takes const&.
S_NodeExecuteContext::~S_NodeExecuteContext() {}

}  // namespace wh::conceptmodule
