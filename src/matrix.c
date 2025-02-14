#include "matrix.h"

Matrix4 Identity(){

    Matrix4 matrix = {
        .data = {
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1}
        }
    };
    return matrix;
}

Matrix4 TranslationMatrix(float tx, float ty, float tz){
    Matrix4 matrix = Identity();

    matrix.data[0][3] = tx; 
    matrix.data[1][3] = ty;
    matrix.data[2][3] = tz;

    return matrix;
}

Matrix4 ScalingMatrix(float sx, float sy, float sz){

    Matrix4 matrix = Identity();
    
    matrix.data[0][0] = sx;
    matrix.data[1][1] = sy;
    matrix.data[2][2] = sz;

    return matrix;

}

// rotate about the x axis
Matrix4 MakeMatrixRotateX(float angle){

    Matrix4 matrix = Identity();

    matrix.data[1][1] = cos(angle);
    matrix.data[1][2] = -sin(angle);
    matrix.data[2][1] = sin(angle);
    matrix.data[2][2] = cos(angle);

    return matrix;

}

// rotate about the y axis 
Matrix4 MakeMatrixRotateY(float angle){
    Matrix4 matrix = Identity();

    matrix.data[0][0] = cos(angle);
    matrix.data[0][2] = sin(angle);
    matrix.data[2][0] = -sin(angle);
    matrix.data[2][2] = cos(angle);

    return matrix;
}

// rotate about the z axis
Matrix4 MakeMatrixRotateZ(float angle){
    Matrix4 matrix = Identity();

    matrix.data[0][0] = cos(angle);
    matrix.data[0][1] = -sin(angle);
    matrix.data[1][0] = sin(angle);
    matrix.data[1][1] = cos(angle);

    return matrix;

}


Matrix4 MultiplyByMatrix(const Matrix4 matrix1, const Matrix4 matrix2){
    Matrix4 matrix = Identity();
    
    for(int x = 0; x < 4; x++){ // outer loop (rows)
        for(int y = 0; y < 4; y++){ // middle loop (columns)
            matrix.data[x][y] = 0;
            for(int i = 0; i < 4; i++){ // inner loop (dot product)
                matrix.data[x][y] += matrix1.data[x][i] * matrix2.data[i][y];
                printf("Matrix value at [%d][%d]: %f", x,y, matrix.data[x][y]);
            }
        }
    }
    return matrix;
}

// making the model matrix 

Matrix4 MultiplyRotationMatrix(Matrix4 x, Matrix4 y, Matrix4 z){

    Matrix4 result = Identity();

    // r = rz * ry * rx --> r = rz * (ry * rx)
    result = MultiplyByMatrix(y,x); 
    result = MultiplyByMatrix(z,result);

    return result;
}

Matrix4 ModelMatrix(Matrix4 transformation, Matrix4 rotation, Matrix4 scaling){

    Matrix4 result = Identity();
     //  m = t * r * s --> m = t * (r * s)

    result = MultiplyByMatrix(rotation,scaling);
    result = MultiplyByMatrix(transformation, result);

    return result;

}


Matrix4 ProjectionMatrix(const float FOV, const float width,const float height ,const float znear, const float zfar){

    double a,b,c,d; 

    Matrix4 result = Identity();

    a = 1 / (tan(FOV/2) * ASPECT); 

    b = 1 / (tan(FOV/2));

    c = (zfar + znear) / (znear - zfar);

    d = (2 * zfar * znear) / (znear - zfar);

    result.data[0][0] = a;
    result.data[1][1] = b;
    result.data[2][2] = c;
    result.data[2][3] = d;
}

Matrix4 ViewMatrix(const Vec3 x, const Vec3 y, const Vec3 z){

    Matrix4 result = Identity();
    result.data[0][0] = x.x;
    result.data[0][1] = x.y;
    result.data[0][2] = x.z;
}