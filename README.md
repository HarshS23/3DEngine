# 3DEngine

trying to make a 3d engine 

# What is a 3D Engine 
    A 3d engine is a software, that is used to render 3 dimensional object on a 2 dimensional screen. 

# Core functions of a 3D Engine 
    Render 
        - needs to be able to display 3 Dimenisonal objects on to a 2 Dimensional screen 
        - need to handle lighting, shading, texturing, the effects reflections have upon an object 
    
    input handling 
        - Should capture user-input from devices, such as a keyboard, mouse, controllers
    
    Shaders and Post Processing 
        - Should utilize GPU and create visual effects 
    
    Scene management 
        - Should be able to place the object at the center of the screen 
        - should be able to organize and optimize the rendering of a screen
    
# Creating a 3D Engine (Steps)
    1. Render pipeline  
        - learn basics of 3D graphics, such as Vectors, polygons,
           shaders and lighting. 
        - setting up a graphics api: I will be using SDL2, and will be programming 
          in C99 for this project. 
        - Render 2D triangles, before expanding to 3D triangles 
        - implement Camera support 
    
    2. Lighting and Shading 
        - implement basic lighting models such as ambient lighting, diffuesd lighting, and specular lighting. 
        - write shaders to handle lighting, colors and materials 
    
    3. User input 
        - taking in user input such as WASD, to move the camera around the render enviroment 
    
    4. Add Skeletal Support 
        - Show skeletons of the object by using the 3D triangles 
    
    5. Optimization 
        - Implement Level of detail to decrease details for objects far from camera, and increase detail 
          of objects closer to the camera. 


# SIDENOTE 
    v x y z → Defines a vertex with (x, y, z) coordinates.
    vt u v → Defines a texture coordinate (u, v values for mapping a texture).
    vn x y z → Defines a normal vector.
    f v1/vt1/vn1 v2/vt2/vn2 v3/vt3/vn3 → Defines a face by specifying vertex indices, texture coordinate indices, and normal indices.
