#include "matrix.h"

// Memory:
// +------+------+------+------+
// | 0,0  | 0,1  | 0,2  | 0,3  |
// +------+------+------+------+
// | 1,0  | 1,1  | 1,2  | 1,3  |
// +------+------+------+------+
// | 2,0  | 2,1  | 2,2  | 2,3  |
// +------+------+------+------+
// | 3,0  | 3,1  | 3,2  | 3,3  |
// +------+------+------+------+


Matrix4 Identity(void){
    /*

        | 1 0 0 0 |
        | 0 1 0 0 |
        | 0 0 1 0 |
        | 0 0 0 1 |

    */

   Matrix4 mat4x4  = {
    .matrix = {
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1},
    }
   };
}

// translation matrix
Matrix4 translation_matrix(const float tx, const float ty, const float tz){
    // let m be the identity matrix 
    Matrix4 m = Identity(); 
    m.matrix[0][3] = tx; 
    m.matrix[1][3] = ty; 
    m.matrix[2][3] = tz;
    return m;
}

Matrix4 scale_matrix(const float sx, const float sy, const float sz){
    Matrix4 m = Identity(); 
    m.matrix[0][0] = sx; 
    m.matrix[1][1] = sy; 
    m.matrix[2][2] = sz;
}

Matrix4 rotation_matrix_x_axis(const float angle){
    Matrix4 m = Identity();
    m.matrix[1][1] = cos(angle);
    m.matrix[1][2] = -sin(angle);
    m.matrix[2][1] = sin(angle);
    m.matrix[2][2] = cos(angle);
    return m;
}

Matrix4 rotation_matrix_y_axis(const float angle){
    Matrix4 m = Identity();
    m.matrix[0][0] = cos(angle);
    m.matrix[0][2] = sin(angle);
    m.matrix[2][0] = -sin(angle);
    m.matrix[2][2] = cos(angle);
    return m;
}

Matrix4 rotation_matrix_z_axis(const float angle){
    Matrix4 m = Identity();
    m.matrix[0][0] = cos(angle);
    m.matrix[0][1] = -sin(angle);
    m.matrix[1][0] = sin(angle);
    m.matrix[2][1] = cos(angle);
    return m;
}

Matrix4 ProjectionMatrix(const float fov, const float aspect, const float znear, const float zfar){
     // aspect ratio is (width / height )
    float a = 1 / (tan(fov / 2) * aspect);
    float b = 1 / (tan(fov / 2)); 
    float c = (zfar + znear) / (znear - zfar);
    float d = (2 * zfar * znear) / (znear - zfar);

    Matrix4 m = Identity(); 
    m.matrix[0][0] = a;
    m.matrix[1][1] = b; 
    m.matrix[2][2] = c; 
    m.matrix[2][3] = d;
}

Matrix4 Multiply_Matrices(Matrix4 m1, Matrix4 m2){

    return 1;
}