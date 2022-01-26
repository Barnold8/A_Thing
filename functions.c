#include "functions.h"

// anime where people are countries
// kirby ascii art

char** returnIMG(char* filename, int* arr_len){

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
        arrSize ++;
    }
   
    *arr_len = arrSize;

    fclose(fptr);

    if(!(strArray = (char**)malloc(sizeof(char*)*arrSize))){
        fprintf(stderr,"ERROR: Couldnt malloc memory in returnIMG function");
        return NULL;
    }
    
    if(currLine){free(currLine);}

    // Get line amount of file for amount of strings of file 

    // Assign strings to string array 

    if(!(fptr = fopen(filename,"r"))){
        fprintf(stderr,"ERROR: Couldnt read file with filename %s\n",filename);
        return NULL;
    }
    arrSize = 0;
    while ((read = getline(&currLine, &len, fptr)) != -1) {
        // printf("%s",currLine);
        strArray[arrSize] = (char*)malloc(sizeof(char)*(strlen(currLine))+1);
        arrSize ++;
        
        strArray[arrSize] = currLine;
        // printf("Curr line %s\n",currLine);
        
    }

    fclose(fptr);


    // Assign strings to string array 

    return strArray;

}

void setup(){

    system("chcp 65001");
    system("title Kirby's game! (Kirby's great adventure)");
    system("cls");
    
}

void titleSequence(char* kirb, char* title){


    int arrLen = 0;
    int i;
    char** strARR = returnIMG(kirb,&arrLen);
    
    printf("ArrLen %d\n",arrLen);

    for (i = 0; i < arrLen; i++)
    {
        printf("%s\n",strARR[i]);
    }
    
    

}
