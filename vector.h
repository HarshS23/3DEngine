#ifndef VECTOR_H
#define VECTOR_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// defines a vertex with x,y,z cordinates 
typedef struct{

    float x;
    float y; 
    float z;

}Vec3;

typedef struct{

    float x; 
    float y;

}Vec2;

// Defines a face by specifing vertex indices ,texture indices, and normal indices 
// format is 
//f v/vt/vn --> Vector indices / textues indices /normal indicies 
// Ex: f 3220/1805/2160 3205/1790/2160 3219/1804/2160 
typedef struct {
    int v1, v2, v3; // vector indcies 
    int vt1, vt2, vt3; // texture indicies 
    int vn1, vn2, vn3; // normal indicies 

}Faces;

typedef struct{
    float u; 
    float v;

}Text;

#endif