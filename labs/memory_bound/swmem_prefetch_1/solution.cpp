#include "solution.hpp"

static int getSumOfDigits(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

int solution(hash_map_t const* hash_map, std::vector<int> const& lookups)
{
    int result = 0;

    for (int val : lookups)
    {
        if (hash_map->find(val)) result += getSumOfDigits(val);
    }

    return result;
}
