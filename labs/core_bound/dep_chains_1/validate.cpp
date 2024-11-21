
#include "solution.hpp"
#include <iostream>
#include <memory>

std::vector<unsigned> vec_from_list(list* l)
{
    std::vector<unsigned> ret{};
    list* h = l;
    while (h)
    {
        ret.push_back(l->value);
        h = h->next;
    }
    return ret;
}

unsigned original_solution(list* l1, list* l2)
{
    unsigned retVal = 0;

    list* head2 = l2;
    while (l1)
    {
        unsigned v = l1->value;
        l2 = head2;
        while (l2)
        {
            if (l2->value == v)
            {
                retVal += get_sum_of_digits(v);
                break;
            }
            l2 = l2->next;
        }
        l1 = l1->next;
    }

    return retVal;
}

int main()
{
    // Init benchmark data
    auto arena1 = list_arena_allocator_t{};
    auto l1 = get_random_list(arena1);
    auto arena2 = list_arena_allocator_t{};
    auto l2 = get_random_list(arena2);

    auto v1 = vec_from_list(l1);
    auto v2 = vec_from_list(l2);

    auto original_result = original_solution(l1, l2);
    auto result = solution(v1, v2);

    if (original_result != result)
    {
        std::cerr << "Validation Failed. Original result = " << original_result << "; Modified version returned = " << result << "\n";
        return 1;
    }

    std::cout << "Validation Successful" << std::endl;
    return 0;
}
