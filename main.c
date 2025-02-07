#include "main.h"
//gcc -o obj_parser main.c -lm -L/opt/homebrew/lib -I/opt/homebrew/include -lSDL2
// # Blender 3.6.5
// # www.blender.org
// mtllib air-liner.mtl
// o air-liner

Vec3 *vertices = NULL; // stores the array of vertices 
int Num_Vertices = 0; // number of vertices in our array

Faces *face = NULL; // array to store faces 
int Num_Faces = 0; // number of faces in our array 

Vec3 *Normal_Vec = NULL;
int Num_Nvec = 0;

Text *texture = NULL; 
int Num_text = 0;

int Num_Lines = 0;


char line[128];
//./obj_parser air-line.obj


void ParseFile(const char *filename);



int main(int argc, char *argv[]){

    ParseFile("air-liner.obj");
    PrintData();


    free(vertices);
    free(face); 
    free(Normal_Vec);
    free(texture);

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

        if (line[0] == '#') continue;

        //defines vertex  v
        if (line[0] == 'v' && line[1] == ' '){
            sscanf(line, "v %f %f %f", &vertices[VIndex].x,  &vertices[VIndex].y, &vertices[VIndex].z);
            VIndex++; 
        }

        // defines faces f
        //f v/vt/vn
        //f 3220/1805/2160 3205/1790/2160 3219/1804/2160 
        if (line[0] == 'f' && line[1] == ' '){
            sscanf(line, "f %d/%d/%d %d/%d/%d %d/%d/%d", &face[FIndex].v1, &face[FIndex].vt1, &face[FIndex].vn1,\
                                                         &face[FIndex].v2, &face[FIndex].vt2, &face[FIndex].vn2,\
                                                         &face[FIndex].v3, &face[FIndex].vt3, &face[FIndex].vn3);
            FIndex++;
        }

        // defines normal vector  vn 
        if (line[0] == 'v' && line [1] == 'n' && line[2] == ' '){
            sscanf(line, "vn %f %f %f", &Normal_Vec[NIndex].x,&Normal_Vec[NIndex].y ,&Normal_Vec[NIndex].z);
            NIndex++;
        }

        if (line[0] == 'v' && line[1] == 't' && line[2] == ' '){
            sscanf(line, "vt %f %f", &texture[TIndex].u, &texture[TIndex].v);
            TIndex++;
        }
    } 

    fclose(fread);

}

void PrintData(){

    printf("\nSTART OF FILE\n");
    printf("NUM OF LINES: %d\n", Num_Vertices);

    for(int i = 0; i < Num_Vertices; i++){
        printf("Line Number (%d) :v %f %f %f\n",i + 1,vertices[i].x,vertices[i].y,vertices[i].z);
    }

    printf("\nEND OF FILE\n");
}