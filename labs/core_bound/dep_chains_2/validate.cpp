#include "solution.hpp"
#include <cmath>
#include <iostream>
#include <limits>
#include <random>

static bool equals(particle_buffer_t const& p1, particle_buffer_t const& p2)
{
    constexpr int max_errs = 10;
    float const epsilon = std::sqrt(std::numeric_limits<float>::epsilon());
    int errors = 0;

    for (int i = 0; i < p1.size(); i++)
    {
        float x1 = p1[i].x;
        float x2 = p2[i].x;
        float y1 = p1[i].y;
        float y2 = p2[i].y;
        float xerror = std::abs(x1 - x2);
        float yerror = std::abs(y1 - y2);
        if (xerror >= epsilon || yerror >= epsilon)
        {
            std::cerr << "Result: p1[" << i << "] = {" << x1 << "," << y1 << "}"
                      << ". Expected : p1[" << i << "] = {" << x2 << "," << y2 << "}" << std::endl;
            if (++errors >= max_errs) return false;
        }
    }
    return 0 == errors;
}

// For validation we use a deterministic random number generator
// that uses a global state and thus always generates the same sequence of numbers
struct rng_for_validation
{
    rng_for_validation(uint32_t seed) { (void)seed; }

    static uint32_t val;

    uint32_t gen() { return val++; }
};

uint32_t rng_for_validation::val = 0;

void random_particle_motion_original(particle_buffer_t& particles, uint32_t seed)
{
    rng_for_validation rng(seed);
    for (int i = 0; i < steps_v; i++)
        for (auto& p : particles)
        {
            uint32_t angle = rng.gen();
            float angle_rad = angle * degree_to_radian_v;
            p.x += cosine(angle_rad) * p.velocity;
            p.y += sine(angle_rad) * p.velocity;
        }
}

int main()
{
    // Init benchmark data
    auto particles = init_particles();
    auto particlesCopy = particles;

    std::random_device r;
    std::mt19937_64 random_engine(r());
    std::uniform_int_distribution<uint32_t> distrib(0, std::numeric_limits<uint32_t>::max());

    auto seed = distrib(random_engine);
    random_particle_motion_original(particlesCopy, seed);
    rng_for_validation::val = 0;
    random_particle_motion<rng_for_validation>(particles, seed);

    if (!equals(particlesCopy, particles))
    {
        std::cerr << "Validation Failed." << "\n";
        return 1;
    }

    std::cout << "Validation Successful" << std::endl;
    return 0;
}
