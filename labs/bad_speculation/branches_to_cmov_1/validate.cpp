
#include "solution.hpp"
#include <iostream>

class life_original
{

public:
    using grid = std::vector<std::vector<int>>;

private:
    grid current;
    grid future;

public:
    void reset(grid const& grid) { current = future = grid; }

    int population_count()
    {
        int pop_count = 0;
        for (auto& row : current)
            for (auto& item : row) pop_count += item;
        return pop_count;
    }

    void print_curr_grid() const
    {
        for (auto const& row : current)
        {
            for (auto const& item : row) item ? std::cout << "x " : std::cout << ". ";
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    // Simulate the next generation of life
    void next_sim()
    {
        //printCurrentGrid();
        auto const M = current.size();
        auto const N = current[0].size();

        // Loop through every cell
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int alive_neighbors = 0;
                // finding the number of neighbours that are alive
                for (int p = -1; p <= 1; p++)
                {  // row-offet (-1,0,1)
                    for (int q = -1; q <= 1; q++)
                    {                            // col-offset (-1,0,1)
                        if ((i + p < 0 ||        // if row offset less than UPPER boundary
                             (i + p > M - 1) ||  // if row offset more than LOWER boundary
                             (j + q < 0) ||      // if column offset less than LEFT boundary
                             (j + q > N - 1)))   // if column offset more than RIGHT boundary
                            continue;
                        alive_neighbors += current[i + p][j + q];
                    }
                }
                // The cell needs to be subtracted from
                // its neighbours as it was counted before
                alive_neighbors -= current[i][j];

                // Implementing the Rules of Life:
                switch (alive_neighbors)
                {
                // 1. Cell is lonely and dies
                case 0:
                case 1: future[i][j] = 0; break;
                // 2. Remains the same
                case 2: future[i][j] = current[i][j]; break;
                // 3. A new cell is born
                case 3: future[i][j] = 1; break;
                // 4. Cell dies due to over population
                default: future[i][j] = 0;
                }
            }
        }
        std::swap(current, future);
    }
};

std::vector<int> original_solution(std::vector<life_original::grid> const& grids)
{
    std::vector<int> pop_counts;
    pop_counts.reserve(grids.size());

    life_original life;
    for (auto const& grid : grids)
    {
        life.reset(grid);
        for (int i = 0; i < sim_count_v; i++) life.next_sim();
        pop_counts.push_back(life.population_count());
    }

    return pop_counts;
}

int main()
{
    // Init benchmark data
    std::vector<life_original::grid> grids;
    grids.reserve(number_of_grids_v);
    for (int i = 0; i < number_of_grids_v; i++) grids.emplace_back(init_rand());

    auto original_result = original_solution(grids);
    auto result = solution(grids);

    if (original_result != result)
    {
        std::cerr << "Validation Failed. Population count doesn't match" << "\n";
        return 1;
    }

    std::cout << "Validation Successful" << std::endl;
    return 0;
}
