#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>

#include <temp.h>
#include <list.h>
#include <screen.h>
#include <particle.h>

void
add_element (particle * type)
{}

particle *
construct_particle (const particle * type)
{
    particle * part = malloc (sizeof (particle));
    memcpy (part, type, sizeof (type));
    return part;
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
    dust->color = 255+256+256;
    particle * particle2 = construct_particle (dust);
    grid[Y_RES/2][X_RES/2] = construct_particle (dust);
    printf ("Color of particle: %d\n", dust->color);
    printf ("temp of particle2: %d\n", particle2->temp_p);
    return 0;
}
