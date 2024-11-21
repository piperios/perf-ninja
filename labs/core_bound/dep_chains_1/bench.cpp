
#include "benchmark/benchmark.h"
#include "solution.hpp"
#include <memory>

static void bench1(benchmark::State& state)
{
    // Init benchmark data
    auto v1 = get_random_vector();
    auto v2 = get_random_vector();

    // Run the benchmark
    for (auto _ : state)
    {
        auto output = solution(v1, v2);
        benchmark::DoNotOptimize(output);
    }
}

// Register the function as a benchmark and measure time in microseconds
BENCHMARK(bench1)->Unit(benchmark::kMillisecond);

// Run the benchmark
BENCHMARK_MAIN();
