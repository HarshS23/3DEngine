#include "textures.h"

texture_2c TextClone(texture_2c *tex){
    return (texture_2c){
        .u = tex->u,
        .v = tex->v,
    };
}

