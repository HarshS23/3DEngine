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
    Vec3 output = {0,0,0};

    output.x *= x; 
    output.y *= x; 
    output.z *= x;

    return output;
}

Vec3 div_v3(Vec3 v ,  int x){
    Vec3 output = {0,0,0};

    output.x /= x; 
    output.y /= x; 
    output.z /= x;

    return output;

}

float dot_v3(Vec3 v1, Vec3 v2){
    return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}

float len_v3(Vec3 v){
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

Vec3 normalize_v3(Vec3 v1){
    float mag = len_v3(v1);
    if (mag == 0){
        return (Vec3){0,0,0};
    }else{
        return mul_v3(v1, 1.0f);
    }
}

void print_v3(Vec3 v){
    printf("\nVECTOR: v.x: %lf, v.y: %lf, v.z: %lf ----\n", v.x, v.y, v.z);
}