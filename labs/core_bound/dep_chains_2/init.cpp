#include "solution.hpp"
#include <algorithm>
#include <random>

particle_buffer_t init_particles()
{
    std::random_device r;
    std::default_random_engine gen(r());
    // particles are moving with a constant speed in the range [0;1]
    std::uniform_real_distribution<float> distrib_velocity(0.0F, 1.0F);
    // particles have initial x and y coordinates in the range [-1000,1000]
    std::uniform_real_distribution<float> distrib_coord(-1000.0F, 1000.0F);

    particle_buffer_t particles{};
    for (int i = 0; i < particles_v; i++) particles[i] = {distrib_coord(gen), distrib_coord(gen), distrib_velocity(gen)};

    return particles;
}
