#include "solution.hpp"
#include <algorithm>
#include <iostream>
#include <limits>
#include <random>

std::vector<unsigned> get_random_vector()
{
    std::random_device r;
    std::default_random_engine generator(r());
    std::uniform_int_distribution<unsigned> distribution(0, std::numeric_limits<random_range_t>::max());

    std::vector<unsigned> retVector;
    retVector.reserve(N);
    // generate random values.
    for (int i = 0; i < N; i++) { retVector.push_back(distribution(generator)); }
    // remove duplicates
    std::sort(retVector.begin(), retVector.end());
    retVector.erase(std::unique(retVector.begin(), retVector.end()), retVector.end());

    // reshuffle
    std::shuffle(std::begin(retVector), std::end(retVector), generator);
    return retVector;
}

list* get_random_list(list_arena_allocator_t& allocator)
{
    auto createNode = [&](unsigned v)
    {
        list* n = allocator.allocate();
        if (!n) return n;  // consider crash
        n->value = v;
        n->next = nullptr;
        return n;
    };

    list* head = createNode(0);
    if (!head) return nullptr;

    list* l = head;
    std::vector<unsigned> randoms = get_random_vector();
    for (auto v : randoms)
    {
        l->next = createNode(v);
        if (!l->next) return nullptr;  // consider crash
        l = l->next;
    }
    return head;
}

// For debugging
void print_list(list* l)
{
    while (l)
    {
        std::cout << l->value << " ";
        l = l->next;
    }
    std::cout << '\n';
}
