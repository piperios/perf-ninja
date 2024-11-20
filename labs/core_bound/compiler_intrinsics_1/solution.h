
#include <cstdint>
#include <vector>

using input_buffer_t = std::vector<uint8_t>;
using output_buffer_t = std::vector<uint16_t>;

constexpr uint8_t radius_v = 13;  // assume diameter (2 * radius + 1) to be less than 256 so results fits in uint16_t

void init(input_buffer_t& data);
void zero(output_buffer_t& data, std::size_t size);
void smoothen_image(input_buffer_t const& inA, uint8_t radius, output_buffer_t& outResult);
