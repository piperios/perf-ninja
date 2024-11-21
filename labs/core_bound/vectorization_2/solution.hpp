
#include <array>
#include <cstdint>

// Assume this constant never changes
constexpr std::size_t N = 64 * 1024;

using blob = std::array<uint16_t, N>;

void init(blob& blob);
uint16_t checksum(blob const& blob);
