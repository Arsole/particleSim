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

#ifndef _PARTICLE_H
#define _PARTICLE_H
/*
   Masks is like this, from left to right, 1 is true, 0 is false
   conducts, dangerous, explodes, insulator(heat), acid,
   from right to left,
   solid, powder, liquid, gas, 
*/
struct particle
{
    uint32_t mask;
    temp temp_p;  // Particle temp
    temp f_point; // Freezing point
    temp m_point; // Melting point
    temp b_point; // Boiling point
    temp p_point; // Plasma point, could use a better name
    uint32_t color;
    unsigned int weight;
};
typedef struct particle particle;
#endif // _PARTICLE_H
