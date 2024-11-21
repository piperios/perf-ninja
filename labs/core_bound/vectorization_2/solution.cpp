#include "solution.hpp"

#include <cstdint>
#include <numeric>

uint16_t checksum(blob const& blob)
{
    uint32_t acc = std::accumulate(blob.cbegin(), blob.cend(), 0);

    acc = (acc >> 16) + (acc & 0xFFFF);
    acc = (acc >> 16) + (acc & 0xFFFF);

    return acc;
}
