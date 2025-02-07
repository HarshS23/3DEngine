#include "main.h"


int main(int argc, char *argv[]){

    Vec3 *vertices = NULL; // stores the array of vertices 
    int Num_Vertices = 0; // number of vertices in our array

    Faces *face = NULL; // array to store faces 
    int Num_Faces = 0; // number of faces in our array 

    char line[128];

    FILE *fread = fopen("air-line.obj", "r");

    if (fread == NULL){
        printf("FILE FAILED TO OPEN\n PLEASE UPLOAD AN OBJECT FILE\n");
        exit(EXIT_FAILURE);
    }

    while(fgets(line, sizeof(line), fread)){
        if(line[0] == 'v' && line[1] == ' ') Num_Vertices++;
        if (line[0] == 'f' && line[1] == ' ')Num_Faces++;
    }

    // allocating memory 
    


    //printf("Enter an object file: ");


    return 0;
}