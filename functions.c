#include "functions.h"

// anime where people are countries
// kirby ascii art

void returnIMG(char* filename){

    FILE* fptr;
    char* currLine = NULL;
    size_t len = 0;
    ssize_t read;
    char** strArray;
    int arrSize = 0;
    int i;

    // Get line amount of file for amount of strings of file 

    if(!(fptr = fopen(filename,"r"))){
        fprintf(stderr,"ERROR: Couldnt read file with filename %s\n",filename);
        return NULL;
    }
    
    while ((read = getline(&currLine, &len, fptr)) != -1) {
        printf("%s",currLine);
    }

    fclose(fptr);
    
    if(currLine){free(currLine);}

    // Get line amount of file for amount of strings of file 

}

void setup(){

    system("chcp 65001");
    system("title Kirby's game! (Kirby's great adventure)");
    system("cls");
    
}

void titleSequence(char* kirb, char* title){


    returnIMG(title);

}
