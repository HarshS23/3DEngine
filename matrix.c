#include "matrix.h"
#include <stddef.h>
#include "vector.h"
#include "math.h"


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
    Matrix4 m;

    for(size_t i; i < 4; i++){
        for(size_t j; j < 4; j++){
            m.matrix[i][j] = m1.matrix[i][0] * m2.matrix[j][0]\
                + m1.matrix[i][1] * m2.matrix[j][1]
                + m1.matrix[i][2] * m2.matrix[j][2]
                + m1.matrix[i][3] * m2.matrix[j][3];
        }
    }

    return m;
}

Vec4 Multiply_Matrix_by_Vector(const Matrix4 m, const Vec4 v){
    Vec4 vector; 
    vector.x = (m.matrix[0][0] * v.x) + (m.matrix[0][1] * v.y) + (m.matrix[0][2] * v.z) + (m.matrix[0][3] * v.w);
    vector.y = (m.matrix[1][0] * v.x) + (m.matrix[1][1] * v.y) + (m.matrix[1][2] * v.z) + (m.matrix[1][3] * v.w);
    vector.z = (m.matrix[2][0] * v.x) + (m.matrix[2][1] * v.y) + (m.matrix[2][2] * v.z) + (m.matrix[2][3] * v.w);
    vector.w = (m.matrix[3][0] * v.x) + (m.matrix[3][1] * v.y) + (m.matrix[3][2] * v.z) + (m.matrix[3][3] * v.w);

    return vector;
}

Vec4 Multiply_Projection_by_Vector(const Matrix4 matrixProj, const Vec4 vector){
    Vec4 result = Multiply_Matrix_by_Vector(matrixProj, vector);

    if(result.w != 0.0){
        result.x /= result.w;
        result.y /= result.w;
        result.z /= result.w;
    }

    return result;
}

Matrix4 View_Matrix(Vec3 eye, Vec3 target, Vec3 up){
    Vec3 z = sub_v3(target, eye); // forward Vector 
    normalize_v3(&z); // normalized forward Vector 
    Vec3 x = cross_v3(up,z); // right Vector
    normalize_v3(&x);
    Vec3 y = cross_v3(z,x); 

    Matrix4 m = {
        .matrix = {{x.x, x.y, x.z, -dot_v3(x,y)},
                 {y.x, y.y, y.z, -dot_v3(y,eye)},
                 {z.x, z.y, z.z, -dot_v3(z,eye)},
                 {0,0,0,1}}
    };
    return m;
} 