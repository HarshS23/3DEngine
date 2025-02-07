#ifndef CAMERA_H
#define CAMERA_H

#include "vector.h"


typedef struct {
    Vec3 position;  // 3D position of the camera
    float yaw;      // Rotation around the Y-axis
} Camera;


Camera camera = { {0.0f, 0.0f, -5.0f}, 0.0f };
#endif