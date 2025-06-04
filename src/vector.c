#include "vector.h"

Vec2* Vertices_Converter(const Vec3 *vertices, const int Num_Vertices){
    
    Vec2 *projected = malloc(Num_Vertices * sizeof(Vec2));

    if (projected == NULL){
        printf("UNABLE TO ALLOCATE MEMORY FOR 3D --> 2D CORDINATE CONVERSION\n");
        exit(EXIT_FAILURE);
    }

    // converts all 3d (x,y,z) values to 2d(x,y) values for projection

    for(int i = 0; i < Num_Vertices; i++){

        if (vertices[i].z <= 0){
            projected[i].x = vertices[i].x;
            projected[i].y = vertices[i].y;
        }else{
            projected[i].x = vertices[i].x / vertices[i].z;
            projected[i].y = vertices[i].y / vertices[i].z;
        }
    }

    // for(int i = 0; i < Num_Vertices; i++){
    //     printf("%d: 2D-Coordinate %f %f\n", i, projected[i].x, projected[i].x);
    // }

    return projected;
}


// Vec3 dot(Vec3 a, Vec3 b){

//     return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);

// }