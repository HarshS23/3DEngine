#include "vector.h"

Vec3 add_v3(Vec3 v1, Vec3 v2){
    Vec3 output = {0,0,0};

    output.x = v1.x + v2.x;
    output.y = v1.y + v2.y;
    output.z = v1.z + v2.z;

    return output;  
}

Vec3 sub_v3(Vec3 v1, Vec3 v2){
    Vec3 output = {0,0,0};

    output.x = v1.x - v2.x;
    output.y = v1.y - v2.y;
    output.z = v1.z - v2.z;

    return output;  
    
}

Vec3 mul_v3(Vec3 v,  int x){
    return (Vec3){v.x * x, v.y * x, v.z * x};
}

Vec3 div_v3(Vec3 v ,  int x){
    return (Vec3){v.x / x, v.y / x, v.z / x};
}

float dot_v3(Vec3 v1, Vec3 v2){
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

float len_v3(Vec3 v){
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

void normalize_v3(Vec3 *v){
    float len = len_v3(*v);
    v->x /= len; 
    v->y /= len; 
    v->z /= len; 
}

Vec3 cross_v3(const Vec3 v1, const Vec3 v2){
    Vec3 m;
    m.x = v1.y * v2.z - v1.z * v2.y;
    m.y = v1.z * v2.x - v1.x * v2.z;
    m.z = v1.x * v2.y - v1.y * v2.x;
    return m;
}

void print_v3(Vec3 v){
    printf("\nVECTOR: v.x: %lf, v.y: %lf, v.z: %lf ----\n", v.x, v.y, v.z);
}

