#include "main.h"

Vec3 *vertices = NULL; // stores the array of vertices 
int Num_Vertices = 0; // number of vertices in our array

Faces *face = NULL; // array to store faces 
int Num_Faces = 0; // number of faces in our array 

Vec3 *Normal_Vec = NULL;
int Num_Nvec = 0;

Text *texture = NULL; 
int Num_text = 0;

int Num_Lines = 0;

Vec2 *vertices_2d = NULL;

SDL_Renderer *renderer = NULL;

SDL_Window *window = NULL;

int running = 1;
SDL_Event event;

char line[128];

//int main(int argc, char *argv[]){
int initlizeWindow(void){
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        printf("ERROR UNABLE TO INITLIZE\n");
        exit(EXIT_FAILURE);
    } 

    window = SDL_CreateWindow("3D-RENDER", \
                              SDL_WINDOWPOS_CENTERED,\
                              SDL_WINDOWPOS_CENTERED,\
                              SCREENWIDTH,\
                              SCREENHEIGHT,\
                              0);
    
    if (!window){
        printf("ERROR CREATING SDL WINDOW\n");
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1 , 0);
    //SDL_SetRelativeMouseMode(SDL_TRUE);

    if (renderer == NULL){
        printf("SDL RENDERER UNABLE TO RENDER\n");
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    return 1;
}





int main(){

    ParseFile("object_files/air-liner.obj");
    vertices_2d = Vertices_Converter(vertices, Num_Vertices);
    vertices_2d = ViewportTransformations(vertices_2d, Num_Vertices ,SCREENWIDTH, SCREENHEIGHT);

    initlizeWindow();
    RenderModel(renderer, vertices_2d, face, Num_Faces);

    float yaw = 0.0;
    float pitch = 0.0;
    float sensitivity = 0.0002;


    while(running){

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = 0;
            }

            if(event.type == SDL_KEYDOWN){
                if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
                    running = 0;
                }
            }

            // if(event.type == SDL_MOUSEMOTION){
            //     yaw += event.motion.xrel * sensitivity;
            //     pitch += event.motion.yrel * sensitivity;
            // }
        }

        //printf("yaw: %f\n", yaw);
        // make the background black
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);


        // rendering the model
        RenderModel(renderer, vertices_2d, face, Num_Faces);

        SDL_RenderPresent(renderer);
        
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    // freeing dynamic arrays 
    free(vertices);
    free(face); 
    free(Normal_Vec);
    free(texture);
    free(vertices_2d);

    return 0;
}




void ParseFile(const char *filename){

    FILE *fread = fopen(filename, "r");

    if (fread == NULL){
        printf("FILE FAILED TO OPEN\n PLEASE UPLOAD AN OBJECT FILE\n");
        exit(EXIT_FAILURE);
    }

    while(fgets(line, sizeof(line), fread)){

        if(line[0] == 'v' && line[1] == ' ') Num_Vertices++;
        if (line[0] == 'f' && line[1] == ' ')Num_Faces++;
        if(line[0] == 'v' && line[1] == 'n' && line[2] == ' ') Num_Nvec++;
        if(line[0] == 'v' && line[1] == 't' && line[2] == ' ') Num_text++;
        Num_Lines++;
    }


    // allocating memory 
    vertices = malloc(Num_Vertices * sizeof(Vec3));
    face = malloc(Num_Faces * sizeof(Faces));
    Normal_Vec = malloc(Num_Nvec * sizeof(Vec3));
    texture = malloc(Num_text * sizeof(Text));

    if(vertices == NULL || face == NULL || Normal_Vec == NULL || texture == NULL){
        printf("FAILED TO ALLOCATE MEMORY\n");
        fclose(fread);
        exit(EXIT_FAILURE);
    }

    rewind(fread); // resets the pointer of the file to the beginning 

    int VIndex = 0;
    int FIndex = 0;
    int NIndex = 0;
    int TIndex = 0;

    while(fgets(line, sizeof(line), fread)){

        //defines vertex  v
        if (line[0] == 'v' && line[1] == ' '){
            sscanf(line, "v %f %f %f", &vertices[VIndex].x,  &vertices[VIndex].y, &vertices[VIndex].z);
            VIndex++; 
        }

        // defines faces f
        //f v/vt/vn
        //f 3220/1805/2160 3205/1790/2160 3219/1804/2160 
        else if (line[0] == 'f' && line[1] == ' '){
            sscanf(line, "f %d/%d/%d %d/%d/%d %d/%d/%d", &face[FIndex].v1, &face[FIndex].vt1, &face[FIndex].vn1,\
                                                         &face[FIndex].v2, &face[FIndex].vt2, &face[FIndex].vn2,\
                                                         &face[FIndex].v3, &face[FIndex].vt3, &face[FIndex].vn3);
            FIndex++;
        }

        // defines normal vector  vn 
        else if (line[0] == 'v' && line [1] == 'n' && line[2] == ' '){
            sscanf(line, "vn %f %f %f", &Normal_Vec[NIndex].x,&Normal_Vec[NIndex].y ,&Normal_Vec[NIndex].z);
            NIndex++;
        }

        else if (line[0] == 'v' && line[1] == 't' && line[2] == ' '){
            sscanf(line, "vt %f %f", &texture[TIndex].u, &texture[TIndex].v);
            TIndex++;
        }

        else{
            continue;
        }
    }
    
    for (int i = 0; i < Num_Vertices; i++) {
        vertices[i].z += 1.50;  // Move model backward
    }


    fclose(fread);

}

void PrintData(){

    printf("\nSTART OF FILE\n");
    printf("NUM OF LINES: %d\n", Num_Lines);
    printf("Vertices: \n");


    for(int i = 0; i < Num_Vertices - 1; i++){
        printf("v[%d]: %f %f %f\n", i, vertices[i].x, vertices[i].y, vertices[i].z);
    }

    printf("\n");

    for(int i = 0; i < Num_text - 1; i++){
        printf("vt[%d]: %f %f\n", i, texture[i].u, texture[i].v);
    }

    printf("\n");

    for(int i = 0; i < Num_Nvec - 1 ; i++){
        printf("vn[%d]: %f %f %f\n", i, Normal_Vec[i].x, Normal_Vec[i].y, Normal_Vec[i].z);
    }
    printf("\n");

    for(int i = 0; i < Num_Faces - 1 ; i++){
        printf("f[%d]: %d/%d/%d %d/%d/%d %d/%d/%d\n", i, face[i].v1, face[i].vt1, face[i].vn1,\
                                                           face[i].v2, face[i].vt2, face[i].vn2,\
                                                           face[i].v3, face[i].vt3, face[i].vn3);
    }
    

    printf("\nEND OF FILE\n");
}

void RenderModel(SDL_Renderer *renderer ,const Vec2 *projected, const Faces *face, const int Num_Faces){

    for(int i = 0; i < Num_Faces; i++){

        // the faces in variables
        int v1 = face[i].v1 - 1;
        int v2 = face[i].v2 - 1;
        int v3 = face[i].v3 - 1;

        // now we get the 2d coordinates
        Vec2 p1 = projected[v1];
        Vec2 p2 = projected[v2];
        Vec2 p3 = projected[v3];


        SDL_SetRenderDrawColor(renderer, 255 ,255, 255, 255);
        SDL_RenderDrawLine(renderer, (int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y);
        SDL_RenderDrawLine(renderer, (int)p2.x, (int)p2.y, (int)p3.x, (int)p3.y);
        SDL_RenderDrawLine(renderer, (int)p3.x, (int)p3.y, (int)p1.x, (int)p1.y);

    }

}



