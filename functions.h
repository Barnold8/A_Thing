#ifndef  INCLUDE_CODE
#define  INCLUDE_CODE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


#define pause system("pause");
#define true 1
#define false 0
#define BUFSIZE MAX_PATH

void returnIMG(char* filename);

void setup();

void titleSequence(char* kirb,char*command);

struct LevelSeq* generateLevels();

struct LevelSeq{

    struct LevelSeq* Next; // Pointer to next LL
    char* IMG_TITLE;       // File name for rendering
    int ans;               // Answer to current level

};

void GameLoop();


int ListDirectoryContents(const char *sDir);


#endif