#include "functions.h"

// anime where people are countries
// kirby ascii art

//atoi() string to int

int ListDirectoryContents(const char *sDir) //Refactored from https://stackoverflow.com/questions/2314542/listing-directory-contents-using-c-and-windows
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;

    char sPath[2048];

    //Specify a file mask. *.* = We want everything!
    sprintf(sPath, "%s\\*.*", sDir);

    if((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        printf("Path not found: [%s]\n", sDir);
        return false;
    }

    do
    {
        //Find first file will always return "."
        //    and ".." as the first two directories.
        if(strcmp(fdFile.cFileName, ".") != 0
                && strcmp(fdFile.cFileName, "..") != 0)
        {
            //Build up our file path using the passed in
            //  [sDir] and the file/foldername we just found:
            sprintf(sPath, "%s\\%s", sDir, fdFile.cFileName);

            //Is the entity a File or Folder?
            if(fdFile.dwFileAttributes &FILE_ATTRIBUTE_DIRECTORY)
            {
                printf("Directory: %s\n", sPath);
                ListDirectoryContents(sPath); //Recursion, I love it!
            }
            else{
                printf("File: %s\n", sPath);
            }
        }
    }
    while(FindNextFile(hFind, &fdFile)); //Find the next file.

    FindClose(hFind); //Always, Always, clean things up!

    return true;
}

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

void titleSequence(char* kirb,char* command){

    
    if(strlen(command) >= 7){
        system(command);
    }
    returnIMG(kirb);
}

void GameLoop(struct LevelSeq* startLevel){
    
    generateLevels();

}

char* CWD(){

   TCHAR Buffer[BUFSIZE]; //Windows bloat
   DWORD dwRet;
   char* str;

   if((dwRet = GetCurrentDirectory(BUFSIZE, Buffer) == 0)){
     fprintf(stderr,"ERROR: couldnt get current directory\n");
     return NULL;
   }

   if(!(str = (char*)malloc(sizeof(char)*strlen(Buffer)))){
     fprintf(stderr,"ERROR: couldnt malloc mem in CWD function\n");
     return NULL; 
    }
   
   str = Buffer;
   return str;

}

struct LevelSeq* generateLevels(){

   char* currDIR = CWD();
   printf("Current working directory %s\n",currDIR);



   free(currDIR);

   return NULL;

}
