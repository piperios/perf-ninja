
#include "benchmark/benchmark.h"
#include "solution.hpp"

static void bench1(benchmark::State& state)
{
    // Init benchmark data
    std::vector<life::grid> grids;
    grids.reserve(number_of_grids_v);
    for (int i = 0; i < number_of_grids_v; i++) grids.emplace_back(init_rand());

    // Run the benchmark
    for (auto _ : state)
    {
        auto output = solution(grids);
        benchmark::DoNotOptimize(output);
    }
}

// Register the function as a benchmark and measure time in microseconds
BENCHMARK(bench1)->Unit(benchmark::kMillisecond);

// Run the benchmark
BENCHMARK_MAIN();
