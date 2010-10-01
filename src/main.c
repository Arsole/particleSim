/*
    * Copyright (c) 2010 Felix Wallin <felixwallin@telia.com>
    * All rights reserved.
    *
    * Redistribution and use in source and binary forms, with or without
    * modification, are permitted provided that the following conditions
    * are met:
    * 1. Redistributions of source code must retain the above copyright
    *    notice, this list of conditions and the following disclaimer.
    * 2. Neither the name of the author nor the names of any co-contributors
    *    may be used to endorse or promote products derived from this software
    *    without specific prior written permission.
    *
    * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
    * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
    * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
    * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
    * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
    * SUCH DAMAGE.
*/
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
