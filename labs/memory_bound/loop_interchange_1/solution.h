
#include <array>
#include <cstdint>

// Assume this constant never changes
constexpr int N = 400;

// Square matrix 400 x 400
using Matrix = std::array<std::array<float, N>, N>;

void zero(Matrix& result);
void identity(Matrix& result);
void multiply(Matrix& result, Matrix const& a, Matrix const& b);
Matrix power(Matrix const& input, uint32_t const k);

void init(Matrix& matrix);
