// Stub implementations for idax functions not available in the build
// This is a workaround for missing sources in idax

#include <cstdio>
#include <string_view>

namespace ida {
namespace ui {

// Stub for ida::ui::message - just prints to stdout
void message(std::string_view msg) {
    std::printf("%.*s", static_cast<int>(msg.size()), msg.data());
}

} // namespace ui
} // namespace ida
