#include "solution.hpp"

// Simulates N steps of the game for each starting grid and return population count
std::vector<int> solution(std::vector<life::grid> const& grids)
{
    std::vector<int> pop_counts;
    pop_counts.reserve(grids.size());
    life life;
    for (auto const& grid : grids)
    {
        life.reset(grid);
        for (int i = 0; i < sim_count_v; i++) life.next_sim();
        pop_counts.push_back(life.population_count());
    }

    return pop_counts;
}
