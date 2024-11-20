
#include "benchmark/benchmark.h"
#include "solution.h"
#include <memory>

static void bench_partial_sum(benchmark::State& state)
{
    input_buffer_t in_a;
    init(in_a);

    output_buffer_t outB;
    zero(outB, (int)in_a.size());

    for (auto _ : state)
    {
        smoothen_image(in_a, radius_v, outB);
        benchmark::DoNotOptimize(outB);
    }
}

// Register the function as a benchmark
BENCHMARK(bench_partial_sum)->Unit(benchmark::kMicrosecond);

// Run the benchmark
BENCHMARK_MAIN();
