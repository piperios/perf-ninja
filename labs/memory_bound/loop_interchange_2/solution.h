
#include <cstdint>
#include <memory>
#include <string>

// Applies Gaussian blur to a grayscale image
void blur(uint8_t* output, uint8_t const* input, int const width, int const height, uint8_t* temp);

struct Grayscale
{
    std::unique_ptr<uint8_t[]> data;
    size_t size = 0;
    int width = 0, height = 0;

    bool load(std::string const& filename, int const maxSize);
    void save(std::string const& filename);
};

constexpr int kMaxImageDimension = 32 * 1024;
