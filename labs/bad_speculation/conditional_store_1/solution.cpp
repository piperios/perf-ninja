
#include "solution.h"

// Select items which have S.first in range [lower..upper]
std::size_t select(std::array<S, N>& output, std::array<S, N> const& input, std::uint32_t const lower, std::uint32_t const upper)
{
    std::size_t count = 0;
    for (auto const item : input)
    {
        if ((lower <= item.first) && (item.first <= upper)) { output[count++] = item; }
    }
    return count;
}
