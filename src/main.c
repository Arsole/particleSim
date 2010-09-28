#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>
#include <temp.h>

#define Y_RES 400
#define X_RES 600
typedef unsigned int temp;
struct particle
{
    uint32_t mask;
    temp temp_p;  // Particle temp
    temp f_point; // Freezing point
    temp m_point; // Melting point
    temp b_point; // Boiling point
    temp p_point; // Plasma point, could use a better name
    
};
typedef struct particle particle;

particle *
construct_particle (particle * type)
{
    particle * part = malloc (sizeof (particle));
    memcpy (part, type, sizeof (type));
}

particle * grid[Y_RES][X_RES] = {NULL};

void
destroy_particle (particle * part)
{
    free (part);
}

int
main (int argc, char **argv)
{
    int num_args = argc;
    char ** args = argv;
    int num_threads;
    num_threads = sysconf (_SC_NPROCESSORS_ONLN );
    printf ("Using %d threads", num_threads); 
    particle * dust = malloc (sizeof (particle));
    dust->temp_p = 273;
    grid[Y_RES/2][X_RES/2] = construct_particle (dust);
    return 0;
}
