#include "viewport.h"

Vec2* ViewportTransformations(Vec2 *projected, const int Num_Vertices ,const int SWidth, const int SHeight){

    for(int i = 0; i < Num_Vertices; i++){
        projected[i].x = ((projected[i].x + 1) / 2) * SWidth;
        projected[i].y = (1 - (projected[i].y + 1) / 2) * SHeight;
    }

    for(int i = 0; i < Num_Vertices; i++){
        printf("Viewport cords: ( %f , %f )\n", projected[i].x, projected[i].y);
    }

    return projected;

}

