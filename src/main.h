#ifndef MAIN_H_
#define MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//#include <SDL2/SDL.h>
#include "/opt/homebrew/include/SDL2/SDL.h"
#include "vector.h"


extern Vec3 *vertices; // stores the array of vertices 
extern int Num_Vertices; // number of vertices in our array

extern Faces *face; // array to store faces 
extern int Num_Faces; // number of faces in our array 

extern Vec3 *Normal_Vec;
extern int Num_Nvec;

extern Text *texture; 
extern int Num_text;

extern int Num_Lines;

extern Vec2 *vertices_2d;


extern char line[128];

#define SCREENWIDTH 800 
#define SCREENHEIGHT 600

void ParseFile(const char *filename);
void PrintData();


#endif 

