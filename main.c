// src/main.c
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdlib.h>

#include "vector.h"

#include "matrix.h"

#include "camera.h"


#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

SDL_Window *window = NULL; 
SDL_Renderer *renderer = NULL;


// initlize sdl
void Init(){

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("3D-Graphics Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Vec2 converter(Vec3 point){
    Matrix4 proj = ProjectionMatrix(90.0f * (M_PI / 180.0f), (float)SCREEN_WIDTH / SCREEN_HEIGHT, 0.01, 100.0f);
    Vec4 transformed = Multiply_Matrix_by_Vector(proj, (Vec4){point.x, point.y, point.z, 1.0f});

    if (transformed.w != 0){
        transformed.x /= transformed.w;
        transformed.y /= transformed.w;
    }

    //converting to screen cordinates 
    Vec2 screen_point;

    screen_point.x = (transformed.x + 1) * 0.5f * SCREEN_WIDTH;
    screen_point.y = (1 - transformed.y) * 0.5f * SCREEN_HEIGHT;

    return screen_point;
}

// Handle user input for movement
void handle_input(SDL_Event event, Camera *camera) {
    const float move_speed = 0.1f;
    const float turn_speed = 0.05f;

    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_w: // Move forward
                camera->position.z += move_speed * cos(camera->yaw);
                camera->position.x += move_speed * sin(camera->yaw);
                break;
            case SDLK_s: // Move backward
                camera->position.z -= move_speed * cos(camera->yaw);
                camera->position.x -= move_speed * sin(camera->yaw);
                break;
            case SDLK_a: // Strafe left
                camera->position.x -= move_speed * cos(camera->yaw);
                camera->position.z += move_speed * sin(camera->yaw);
                break;
            case SDLK_d: // Strafe right
                camera->position.x += move_speed * cos(camera->yaw);
                camera->position.z -= move_speed * sin(camera->yaw);
                break;
            case SDLK_LEFT: // Turn left
                camera->yaw -= turn_speed;
                break;
            case SDLK_RIGHT: // Turn right
                camera->yaw += turn_speed;
                break;
        }
    }
}


// Draw a simple 3D grid (as the ground)
void draw_grid(SDL_Renderer *renderer, Camera camera) {
    for (int x = -5; x <= 5; x++) {
        Vec3 start = {x, 0, -5};
        Vec3 end = {x, 0, 5};

        // Apply camera position
        start.x -= camera.position.x;
        start.z -= camera.position.z;
        end.x -= camera.position.x;
        end.z -= camera.position.z;

        Vec2 p1 = converter(start);
        Vec2 p2 = converter(end);
        SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
    }

    for (int z = -5; z <= 5; z++) {
        Vec3 start = {-5, 0, z};
        Vec3 end = {5, 0, z};

        // Apply camera position
        start.x -= camera.position.x;
        start.z -= camera.position.z;
        end.x -= camera.position.x;
        end.z -= camera.position.z;

        Vec2 p1 = converter(start);
        Vec2 p2 = converter(end);
        SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
    }
}


// Main loop
void Run() {
    int running = 1;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            handle_input(event, &camera);
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        draw_grid(renderer, camera); // Draw 3D ground

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
}

// Clean up SDL
void Cleanup() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main() {
    Init();
    Run();
    Cleanup();
    return 0;
}




