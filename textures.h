#ifndef TEXTURES_H
#define TEXTURES_H


typedef struct{
    float u; 
    float v;
}texture_2c;

texture_2c TextClone(texture_2c *tex);
#endif

