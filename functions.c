#include "functions.h"

// anime where people are countries
// kirby ascii art

//atoi() string to int

void returnIMG(char* filename){

    FILE* fptr;
    char* currLine = NULL;
    size_t len = 0;
    ssize_t read;

    // Get line amount of file for amount of strings of file 

    if(!(fptr = fopen(filename,"r"))){
        fprintf(stderr,"ERROR: Couldnt read file with filename %s\n",filename);
        return;
    }
    
    while ((read = getline(&currLine, &len, fptr)) != -1) {
        printf("%s",currLine);
    }

    fclose(fptr);
    
    if(currLine){free(currLine);}

    // Get line amount of file for amount of strings of file 

}

char* CWD(){

   TCHAR Buffer[BUFSIZE]; //Windows bloat
   DWORD dwRet;
   char* str;
 

   if((dwRet = GetCurrentDirectory(BUFSIZE, Buffer) == 0)){
     fprintf(stderr,"ERROR: couldnt get current directory\n");
     return NULL;
   }

   if(!(str = (char*)malloc(sizeof(char)*4096))){
     fprintf(stderr,"ERROR: couldnt malloc mem in CWD function\n");
     return NULL; 
    }
   
   str = Buffer;
   return str;

}



char** ListDirectoryContents(const char* sDir,const char* Directory,int* len) //Refactored from https://stackoverflow.com/questions/2314542/listing-directory-contents-using-c-and-windows
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    int foundDir = 0;
    const char delim[2] = "\\";
    char sPath[2048];
    char*token;
    int stringARRCount = 0;
    char** stringARR = (char**)malloc(sizeof(char*)*20);

    sprintf(sPath, "%s\\*.*", sDir);
 
    if((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        printf("Path not found: [%s]\n", sDir);
        return false;
    }

    while(FindNextFile(hFind, &fdFile)) //Find the next file.
    {

        if(strcmp(fdFile.cFileName, ".") != 0
                && strcmp(fdFile.cFileName, "..") != 0)
        {

            sprintf(sPath, "%s\\%s", sDir, fdFile.cFileName);
            
            if(fdFile.dwFileAttributes &FILE_ATTRIBUTE_DIRECTORY)
            {
                // printf("Directory: %s\n", sPath);

                ListDirectoryContents(sPath,Directory,NULL); 
                
            }
            else{   //This section will add strings to an array where we will be keeping filenames. This allows us to grab files out of a directory
                    //Essentially we are assuming that because the targetted folder is in the param we dont need to return a full file path

                token = strtok(sPath,delim);
                
                while(token){

                    if(foundDir){
    
                        foundDir = 0;
                        stringARR[stringARRCount] = token;
                        stringARRCount++;
                    }

                    else if(strcmp("assets",token)==0){

                        foundDir = 1;

                        

                    }

                    token = strtok(NULL,delim);

                }
                
            }
        }
    }
    

    FindClose(hFind); //Always, Always, clean things up!

    *len = stringARRCount;

    return stringARR;
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



struct LevelSeq* generateLevels(){
    
   int len = 0;
   char ** x = ListDirectoryContents(CWD()," ",&len);
   printf("--LEN-- %d\n",len);

   printf("First elem %s\n",x[0]);



//    free(currDIR);



   return NULL;

}
