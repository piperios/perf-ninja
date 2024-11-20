
#include <array>
#include <cstdint>

// Assume this constant never changes
constexpr std::size_t N = 64 * 1024;

// "first" contains a metric
// "second" contains associated data
using S = std::pair<std::uint32_t, std::uint32_t>;

// Select items which have S.first in range [lower..upper]
std::size_t select(std::array<S, N>& output, std::array<S, N> const& input, std::uint32_t const lower, std::uint32_t const upper);

void init(std::array<S, N>& arr);
