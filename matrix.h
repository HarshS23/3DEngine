#ifndef MATRIX_H
#define MATRIX_H


#include "vector.h"

typedef struct{
    float matrix[4][4];
}Matrix4;

Matrix4 Identity(void);
Matrix4 translation_matrix(const float tx, const float ty, const float tz);
Matrix4 scale_matrix(const float sx, const float sy, const float sz);
Matrix4 rotation_matrix_x_axis(const float angle);
Matrix4 rotation_matrix_y_axis(const float angle);
Matrix4 rotation_matrix_z_axis(const float angle);
Matrix4 ProjectionMatrix(const float fov, const float aspect, const float znear, const float zfar);
Matrix4 Multiply_Matrices(Matrix4 m1, Matrix4 m2);
Vec4 Multiply_Matrix_by_Vector(const Matrix4 m, const Vec4 v);
Vec4 Multiply_Projection_by_Vector(const Matrix4 matrixProj, const Vec4 vector);
Matrix4 View_Matrix(Vec3 eye, Vec3 target, Vec3 up);
#endif



//must add an new line 
// like line 28 
