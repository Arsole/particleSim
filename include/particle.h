#ifndef _PARTICLE_H
#define _PARTICLE_H
struct particle
{
    uint32_t mask;
    temp temp_p;  // Particle temp
    temp f_point; // Freezing point
    temp m_point; // Melting point
    temp b_point; // Boiling point
    temp p_point; // Plasma point, could use a better name
    uint32_t color;
};
typedef struct particle particle;
#endif // _PARTICLE_H
