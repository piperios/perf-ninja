#include "solution.hpp"
#include <algorithm>
#include <random>

// Init random starting grid of the game
life::grid init_rand()
{
    std::random_device r;
    std::mt19937_64 random_engine(r());
    std::uniform_int_distribution<int> distrib(0, 9);

    life::grid ret_grid;

    ret_grid.resize(grid_x_dimension_v);
    for (auto& row : ret_grid)
    {
        row.resize(grid_y_dimension_v + 2);
        std::generate(row.begin(),
                      row.end(),
                      // 70% dead cells and 30% alive cells
                      [&]() { return distrib(random_engine) > 6; });

        row.front() = row.back() = 0;
    }

    ret_grid.insert(ret_grid.begin(), std::vector(grid_y_dimension_v + 2, 0));
    ret_grid.emplace_back(std::vector(grid_y_dimension_v + 2, 0));

    return ret_grid;
}
