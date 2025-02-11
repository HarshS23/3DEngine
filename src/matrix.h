#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector.h"

#define SCREENWIDTH 1080 
#define SCREENHEIGHT 920

typedef struct{
    float data[4][4];
}Matrix4;

Matrix4 Identity();
Matrix4 MultiplyMatrix(Matrix4 a, Matrix4 b);
Matrix4 TranslationMatrix(float tx, float ty, float tz);
Matrix4 ScalingMatrix(float sx, float sy, float sz);
Matrix4 MultiplyByVectorMatrix(Matrix4 a, Vec4 v);
Matrix4 MakeMatrixRotateX(float angle);
Matrix4 MakeMatrixRotateY(float angle);
Matrix4 MakeMatrixRotateZ(float angle);
Matrix4 ViewMatrix(Vec3 x, Vec3 y, Vec3 z); // work in progress 
Matrix4 ProjectionMatrix(float FOV, float width,float height ,float znear, float zfar);

#endif