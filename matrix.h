#include "vector.h"

typedef struct{
    float matrix[4][4];
}Matrix4;

void Identity(void);
Matrix4 rotation_matrix(const float tx, const float ty, const float tz);
Matrix4 scale_matrix(const float sx, const float sy, const float sz);
Matrix4 rotation_matrix_xaxis(const float angle);
Matrix4 rotation_matrix_yaxis(const float angle);
Matrix4 rotation_matrix_zaxis(const float angle);
Matrix4 ProjectionMatrix(const float fov, const float aspect, const float znear, const float zfar);
Matrix4 MultiplyMatrices(Matrix4 m1, Matrix4 m2);
Matrix4 Multiply_Matrix_by_Vector(Matrix4 m, Vec4 v);
Matrix4 Multiply_Projection_by_Vector();

 

