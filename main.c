#include "functions.h"


int main(int argc,char** argv){
  
    int inputCode,endState;
    setup();
    
    if(argc == 2){
        titleSequence("assets/title.txt",argv[1]);
    }else{
        titleSequence("assets/title.txt","color D");
    }

    while(inputCode != 10){

        switch(inputCode = getANS()){

            case 1:
                GameLoop(&endState);
                
                
                break;

            case 2:
                system("clear");
                returnIMG("assets/help.txt");
                break;
            
            case 4:
                system("clear");
                titleSequence("assets/title.txt","color D");
                break;
            
            default:
                break;
        }


    }




}
