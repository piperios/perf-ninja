#include "DataPaths.h"
#include <array>
#include <cstdint>

uint32_t solution(char const* file);

// The following implementation is consistent with Boost's CRC32, see
// https://godbolt.org/z/shEaaE6MW
constexpr inline std::array<uint32_t, 256> generate_crc32_table(uint32_t polynomial)
{
    std::array<uint32_t, 256> retval{};
    for (uint32_t i = 0; i < 256u; ++i)
    {
        uint32_t v = i << 24;
        for (int j = 0; j < 8; ++j)
        {
            bool const carry = v & 0x80000000;
            v <<= 1;
            if (carry) v ^= polynomial;
        }
        retval[i] = v;
    }
    return retval;
}

inline void update_crc32(uint32_t& crc, uint8_t v)
{
    constexpr static auto crc32_table = generate_crc32_table(0x1EDC6F41);
    crc = (crc << 8) ^ crc32_table[((crc >> 24) ^ v) & 0xFF];
}
