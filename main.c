// src/main.c
#include <stdio.h>
#include <SDL2/SDL.h>

int main(void) {

    // initlizing SDL2
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    // Creating window 
    SDL_Window *window = SDL_CreateWindow("3D-GRAPHICS_ENGINE", \
                                        SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_SHOWN);
    
    if(!window){
        printf("ERROR,WINDOW DOES NOT EXIST %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // SDL_event loop 
    SDL_Event event; 
    int running = 1; 
    while(running){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = 0;
            }
        }
    }

    // window clean up 
    SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;
}



