#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdint.h>

#include <temp.h>
#include <list.h>
#include <screen.h>
#include <particle.h>
particle * grid[Y_RES][X_RES] = {NULL};
struct position
{
    unsigned int x;
    unsigned int y;
};
typedef struct position position;
void
add_element (particle * type)
{}

void
construct_particle (const particle * type, const position * pos)
{
    particle * part = malloc (sizeof (particle));
    memcpy (part, type, sizeof (type));
    grid[pos->y][pos->x] = part;
}


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
    position * pos = malloc (sizeof (position));
    pos->x = X_RES/2;
    pos->y = Y_RES/2;
    construct_particle (dust, pos);
    printf ("Color of particle: %d\n", grid[Y_RES/2][X_RES/2]->color); //this is obviously not working
    printf ("temp of particle2: %d\n", grid[Y_RES/2][X_RES/2]->temp_p);
    return 0;
}
