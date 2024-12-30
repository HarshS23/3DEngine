#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// 3 dimensional Vector data type 
typedef struct{
    float x; 
    float y; 
    float z;
}Vec3;

Vec3 add_v3(Vec3 v1, Vec3 v2);
Vec3 sub_v3(Vec3 v1, Vec3 v2);
Vec3 mul_v3(Vec3 v, int x);
Vec3 div_v3(Vec3 v, int x);
float dot_v3(Vec3 v1, Vec3 v2);
float len_v3(Vec3 v);
Vec3 normalize_v3(Vec3 v1);
void print_v3(Vec3 v);

