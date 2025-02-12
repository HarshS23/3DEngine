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
Matrix4 MultiplyMatrix(const Matrix4 a, const Matrix4 b);
Matrix4 TranslationMatrix(const float tx, const float ty, const float tz);
Matrix4 ScalingMatrix(const float sx, const float sy, const float sz);
Matrix4 MultiplyByMatrix(const Matrix4 matrix1, const Matrix4 matrix2);
Matrix4 MakeMatrixRotateX(const float angle);
Matrix4 MakeMatrixRotateY(const float angle);
Matrix4 MakeMatrixRotateZ(const float angle);
Matrix4 CombineRotationMatrices(const float angle);
Matrix4 ViewMatrix(const Vec3 x, const Vec3 y, const Vec3 z); // work in progress 
Matrix4 ProjectionMatrix(const float FOV, const float width,const float height ,const float znear, const float zfar);

#endif