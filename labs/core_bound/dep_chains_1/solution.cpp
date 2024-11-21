#include "solution.hpp"
#include <array>
#include <iostream>

unsigned get_sum_of_digits(unsigned n)
{
    unsigned sum = 0;
    while (n != 0)
    {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}
