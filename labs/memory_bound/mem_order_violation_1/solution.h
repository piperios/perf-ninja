#include <array>
#include <cstdint>
#include <memory>
#include <string>

// https://en.wikipedia.org/wiki/Grayscale
struct GrayscaleImage
{
    std::unique_ptr<uint8_t[]> data;
    size_t size = 0;
    int width = 0;
    int height = 0;

    bool load(std::string const& filename, int const maxSize);
    void save(std::string const& filename);
};

// Binary (aka monochrome) image
// https://en.wikipedia.org/wiki/Binary_image
// We will represent binary image in the same way as grayscale.
using BinaryImage = GrayscaleImage;

constexpr int kMaxImageDimension = 32 * 1024;

std::array<uint32_t, 256> computeHistogram(GrayscaleImage const& image);
std::array<uint32_t, 256> computeHistogram_solution(GrayscaleImage const& image);
int calcOtsuThreshold(std::array<uint32_t, 256> const& hist, int totalPixels);
void applyOtsuThreshold(GrayscaleImage& image);
