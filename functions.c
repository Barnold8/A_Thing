#include "functions.h"

char** returnIMG(char* filename){

    FILE* fptr;
    char* currLine = NULL;
    size_t len = 0;
    ssize_t read;
    char** strArray;
    int arrSize = 0;

    if(!(fptr = fopen(filename,"r"))){
        fprintf(stderr,"ERROR: Couldnt read file with filename %s\n",filename);
        return NULL;
    }
    

    while ((read = getline(&currLine, &len, fptr)) != -1) {
        arrSize ++;
    }

    
    fclose(fptr);

    if(!(strArray = (char**)malloc(sizeof(char*)*arrSize))){
        fprintf(stderr,"ERROR: Couldnt malloc memory in returnIMG function");
        return NULL;
    }
    free(strArray);

    if(currLine){free(currLine);}

    return NULL;

}

void setup(){

    system("chcp 65001");
    system("title Kirby's game! (Kirby's great adventure)");
    system("cls");
    

}
void titleSequence(char* kirb, char* title){

    

}
