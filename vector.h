#include <stdio.h>
#include <math.h>

// vector 4 data type (defines points in space)
typedef struct {
    float v; 
    float x; 
    float y; 
    float z;
}Vec4;

typedef struct{

    float x;
    float y; 
    float z;

}Vec3;

typedef struct {
    int v1, v2, v3;
}Faces;