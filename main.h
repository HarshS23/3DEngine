#ifndef MAIN_H_
#define MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <SDL2/SDL.h>
#include "vector.h"


extern Vec3 *vertices; // stores the array of vertices 
extern int Num_Vertices; // number of vertices in our array

extern Faces *face; // array to store faces 
extern int Num_Faces; // number of faces in our array 

extern Vec3 *Normal_Vec;
extern int Num_Nvec;

extern Text *texture; 
extern int Num_text;


extern char line[128];

void ParseFile(const char *filename);


#endif 

