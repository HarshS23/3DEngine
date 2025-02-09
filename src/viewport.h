#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector.h"

//origin is top left (0,0)

#define SCREENWIDTH 1080 
#define SCREENHEIGHT 920

Vec2* ViewportTransformations(Vec2 *projected, const int Num_Vertices ,const int SWidth, const int SHeight);









#endif
