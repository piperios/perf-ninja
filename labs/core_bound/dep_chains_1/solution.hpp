#include "arena.hpp"
#include <vector>

constexpr unsigned N = 10000;
using random_range_t = unsigned short;

struct list
{
    list* next;
    unsigned value;
};

using list_arena_allocator_t = arena<list, sizeof(list) * N>;

list* get_random_list(list_arena_allocator_t& allocator);
std::vector<unsigned> get_random_vector();

void print_list(list* l);

unsigned get_sum_of_digits(unsigned n);

unsigned solution(list* l1, list* l2);

constexpr unsigned solution(std::vector<unsigned> const& l1, std::vector<unsigned> const& l2)
{

    auto get_sum_of_digits = [](unsigned n) -> unsigned
    {
        unsigned sum = 0;
        while (n != 0)
        {
            sum = sum + n % 10;
            n = n / 10;
        }
        return sum;
    };

    unsigned ret_val = 0;
    for (auto const v1 : l1)
        for (auto const v2 : l2)
            if (v1 == v2)
            {
                ret_val += get_sum_of_digits(v1);
                break;
            }

    return ret_val;
}
