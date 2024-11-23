
#include "benchmark/benchmark.h"
#include "solution.hpp"

static void bench1(benchmark::State& state)
{
    // Init benchmark data
    auto particles = init_particles();

    // Run the benchmark
    for (auto _ : state)
    {
        random_particle_motion<xor_shift32>(particles, steps_v);
        benchmark::DoNotOptimize(particles);
    }
}

// Register the function as a benchmark and measure time in microseconds
BENCHMARK(bench1)->Unit(benchmark::kMillisecond);

// Run the benchmark
BENCHMARK_MAIN();
