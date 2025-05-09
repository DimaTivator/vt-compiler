#include "backend_utils.h"

namespace vt::back {

void PrintASM(const Asm& asm_code, std::ostream& os) {
    for (const auto& line : asm_code) {
        os << line << "\n";
    }
}

}  // namespace vt::back
