#pragma once

#include <array>
#include <cmath>
#include <cstdint>

// The number of motion simulation steps.
constexpr uint32_t steps_v = 10000;
// The number of paticles to simulate.
constexpr uint32_t particles_v = 1000;

struct particle
{
    float x;
    float y;
    float velocity;
};

using particle_buffer_t = std::array<particle, particles_v>;

// Initialize the particles with random coordinates and velocities.
particle_buffer_t init_particles();

// Medium-quality random number generator.
// https://www.javamex.com/tutorials/random_numbers/xorshift.shtml
struct xor_shift32
{
    uint32_t val;

    explicit constexpr xor_shift32(uint32_t seed) : val(seed) {}

    uint32_t gen()
    {
        val ^= (val << 13);
        // val ^= (val >> 17);
        // val ^= (val << 5);
        return val;
    }
};

constexpr double pi_d = 3.141592653589793238463;
constexpr float pi_f = 3.14159265358979F;

// Approximate sine and cosine functions
// https://stackoverflow.com/questions/18662261/fastest-implementation-of-sine-cosine-and-square-root-in-c-doesnt-need-to-b
constexpr float sine(float x)
{
    constexpr float B = 4 / pi_f;
    constexpr float C = -4 / (pi_f * pi_f);

    return (B * x) + (C * x * std::abs(x));
}

constexpr float cosine(float x)
{
    constexpr auto half_pi = pi_f / 2;
    return sine(x + half_pi);
}

// A constant to convert from degrees to radians.
// It maps the random number from [0;UINT32_MAX) to [0;2*pi).
// We do calculations in double precision then convert to float.
constexpr float degree_to_radian_v = (2 * pi_d) / UINT32_MAX;

// Simulate the motion of the particles.
// For every particle, we generate a random angle and move the particle in the corresponding direction.
template <class Rng> void random_particle_motion(particle_buffer_t& particles, uint32_t seed)
{
    Rng rng(seed);
    for (int i = 0; i < steps_v; ++i)
    {
        for (auto& p : particles)
        {
            auto const angle_rad = rng.gen() * degree_to_radian_v;
            auto const sin = sine(angle_rad);
            auto const cos = cosine(angle_rad);

            p.y += sin * p.velocity;
            p.x += cos * p.velocity;
        }
    }
}
