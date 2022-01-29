#include "functions.h"

// anime where people are countries
// kirby ascii art

//atoi() string to int

//https://www.youtube.com/watch?v=AQKi5fBicK0 <- Fail state

int getANS(){
    
    int x;
    
    printf("\nEnter a number: ");
    scanf("%d", &x);  
    return x;

}

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

void GameLoop(int* endState){
    //setup
    char fileNames[LEVEL_AMOUNT][100] = {"assets/kirbHappy.txt",
    "assets/yoshi.txt",
    "assets/yoshiSadge.txt",
    "assets/cool.txt",
    "assets/kirbGun.txt",
    "assets/police.txt",
       
    };
    char dialogue[LEVEL_AMOUNT][1024] = {"\nYou see kirby, go say hi\n\n1. Go say hi\n2. Shout 'HELLO'\n3. Cry\n4. Stay silent\n",

    "\nYoshi appears from around the corner, he asks where you're going.\n\n1. Scream in a wild panic\n2. Make a Yoshi noise\n3. Pretend you dont speak English\n4. Question why Yoshi doesnt speak english\n",

    "\nWith a distained look in his eye, Yoshi stays in silence and slowly walks away.\n\n1. Follow Yoshi and apologise. \n2. Go to kirby\n3. Read the bible\n4. Cough\n",

    "\nYou've got this champ! How do we walk to Kirby?\n\n1. Casual \n2. Normal\n3. Like a Yakuza\n4. Cool\n",

    "\nDamn right! You're slicker than the slickest in the west. But... oh no..\nKIRBY IS SLICKER, HE PULLS A GUN ON YOU!\n\n1. Breakdance\n2. DanceBreak\n3. FanceHake\n4. The fitness gram pacer test\n",
    
    "\n\nWhile breakdancing, you astonished kirby, a glint in his eye reflects a security camera.\nThis wakes a security guard up and he immediately calls the police.\nYou leave questioning your day so far...\n\nType anything to continue....\nWrite 10 to continue\n"
    };

    int answers[6] = {1,4,2,4,1,10};
    int lives = 10;
    int currPosition = 0;
    int ans = 0;

    
    //

    while(lives != 0 || ans != 10){
        if(currPosition > LEVEL_AMOUNT-1){
             return;
        }

        system("cls");
        printf("\n\n");
        returnIMG(fileNames[currPosition]);
        printf("%s",dialogue[currPosition]);
        ans = getANS();

        if(ans != answers[currPosition]){
            lives--;
        }else{currPosition++;}
    
        
        



    }


    
}

