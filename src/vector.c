#include "vector.h"

Vec2* Vertices_Converter(const Vec3 *vertices, const int Num_Vertices){
    Vec2 *vertices_2d = malloc(Num_Vertices * sizeof(Vec2));

    if (vertices_2d == NULL){
        printf("UNABLE TO ALLOCATE MEMORY FOR 3D --> 2D CORDINATE CONVERSION\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < Num_Vertices; i++){

        if (vertices[i].z <= 0){
            vertices_2d[i].x = vertices[i].x;
            vertices_2d[i].y = vertices[i].y;
        }else{
            vertices_2d[i].x = vertices[i].x / vertices[i].z;
            vertices_2d[i].y = vertices[i].y / vertices[i].z;
        }
    }

    for(int i = 0; i < Num_Vertices; i++){
        printf("%d: 2D-Coordinate %f %f\n", i, vertices_2d[i].x, vertices_2d[i].x);
    }

    return vertices_2d;
}
