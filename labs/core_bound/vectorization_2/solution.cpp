#include "solution.hpp"

uint16_t checksum(Blob const& blob)
{
    uint16_t acc = 0;
    for (auto value : blob)
    {
        acc += value;
        acc += acc < value;  // add carry
    }
    return acc;
}
