#include "functions.h"

char** returnIMG(char* filename){

    FILE* fptr;
    char* currLine = NULL;
    size_t len = 0;
    ssize_t read;

    if(!(fptr = fopen(filename,"r"))){
        fprintf(stderr,"ERROR: Couldnt read file with filename %s\n",filename);
        return NULL;
    }
    system("color D");

    while ((read = getline(&currLine, &len, fptr)) != -1) {
        printf("%s", currLine);
    }

    
    fclose(fptr);
    if(currLine){free(currLine);}

    return NULL;

}

void setup(){

    system("chcp 65001");
    system("cls");
    

}
