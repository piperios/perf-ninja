#include <iostream>
#include <numeric>
#include <vector>

constexpr int number_of_grids_v = 16;
constexpr int grid_x_dimension_v = 1024;
constexpr int grid_y_dimension_v = 1024;
constexpr int sim_count_v = 10;

class life
{
public:
    using grid = std::vector<std::vector<int>>;

    void reset(grid const& grid) { current = future = grid; }

    int population_count() const
    {
        return std::accumulate(
            current.begin(), current.end(), 0, [](auto const lhs, auto const& row) { return std::accumulate(row.begin(), row.end(), lhs); });
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
        // Loop through every cell
        for (int i = 1; i <= grid_x_dimension_v; ++i)
        {
            for (int j = 1; j <= grid_y_dimension_v; ++j)
            {
                int alive_neighbors = 0;

                for (auto x = -1; x <= 1; ++x)
                    for (auto y = -1; y <= 1; ++y) alive_neighbors += current[i + x][j + y];

                alive_neighbors -= current[i][j];

                if (alive_neighbors <= 1 || alive_neighbors > 3)
                    future[i][j] = 0;
                else
                    future[i][j] = (alive_neighbors == 2) ? current[i][j] : 1;
            }
        }
        std::swap(current, future);
    }

private:
    grid current;
    grid future;
};

// Init random starting grid of the game
life::grid init_rand();
// Simulates N steps of the game for each starting grid and return population count
std::vector<int> solution(std::vector<life::grid> const& grids);
