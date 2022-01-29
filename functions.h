#ifndef  INCLUDE_CODE
#define  INCLUDE_CODE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <tchar.h> 



#define pause system("pause");
#define true 1
#define false 0
#define BUFSIZE MAX_PATH
#define LEVEL_AMOUNT 6

void returnIMG(char* filename);

void setup();

void titleSequence(char* kirb,char*command);

// struct LevelSeq* generateLevels();

// struct LevelSeq{

//     struct LevelSeq* Next; // Pointer to next LL
//     char* IMG_TITLE;       // File name for rendering
//     int ans;               // Answer to current level

// };

void GameLoop(int* endState);

// char **ListDirectoryContents(const char* sDir,const char* Directory,int* len);

int getANS();





#endif