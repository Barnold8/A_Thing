#include "functions.h"


int main(int argc,char** argv){
  
    int inputCode;
    setup();
    
    if(argc == 2){
        titleSequence("assets/title.txt",argv[1]);
    }else{
        titleSequence("assets/title.txt","color D");
    }

    GameLoop();

    pause

}
