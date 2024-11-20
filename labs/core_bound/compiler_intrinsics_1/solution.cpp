
#include "solution.h"

void smoothen_image(input_buffer_t const& input, uint8_t radius, output_buffer_t& output)
{
    int pos = 0;
    int curr_sum = 0;
    int size = static_cast<int>(input.size());

    // 1. left border - time spend in this loop can be ignored, no need to
    // optimize it
    for (int i = 0; i < std::min<int>(size, radius); ++i) { curr_sum += input[i]; }

    int limit = std::min(radius + 1, size - radius);
    for (pos = 0; pos < limit; ++pos)
    {
        curr_sum += input[pos + radius];
        output[pos] = curr_sum;
    }

    // 2. main loop.
    limit = size - radius;
    for (; pos < limit; ++pos)
    {
        curr_sum -= input[pos - radius - 1];
        curr_sum += input[pos + radius];
        output[pos] = curr_sum;
    }

    // 3. special case, executed only if size <= 2*radius + 1
    limit = std::min(radius + 1, size);
    for (; pos < limit; pos++) { output[pos] = curr_sum; }

    // 4. right border - time spend in this loop can be ignored, no need to
    // optimize it
    for (; pos < size; ++pos)
    {
        curr_sum -= input[pos - radius - 1];
        output[pos] = curr_sum;
    }
}
