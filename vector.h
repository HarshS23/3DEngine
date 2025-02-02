#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// 3 dimensional Vector data type 
typedef struct{
    float x; 
    float y; 
    float z;
}Vec3;

typedef struct{
    float x;
    float y;
    float z; 
    float w;
}Vec4;

Vec3 add_v3(const Vec3 v1, const Vec3 v2);
Vec3 sub_v3(const Vec3 v1, const Vec3 v2);
Vec3 mul_v3(const Vec3 v, const int x);
Vec3 div_v3(const Vec3 v, const int x);
float dot_v3(const Vec3 v1, const Vec3 v2);
float len_v3(const Vec3 v);
void normalize_v3(const Vec3 *v);
Vec3 cross_v3(const Vec3 v1, const Vec3 v2);
void print_v3(const Vec3 v);
#endif