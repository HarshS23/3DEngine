#ifndef CAMERA_H
#define CAMERA_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector.h>


// defines the camera cordinate system
typedef struct{
    Vec3 position;
    Vec3 forward ;
    Vec3 right ;
    Vec3 up ;
}Camera;

#endif