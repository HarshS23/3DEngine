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
            for(int i = 0; i < 4; i++){ // inner loop (dot product)

                void;
            }
        }
    }

    return matrix;
}


