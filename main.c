#include "functions.h"


int main(int argc,char** argv){
  
    int inputCode,endState;
    setup();
    


    while(inputCode != 10){
        system("cls");
        if(argc == 2){
            titleSequence("assets/title.txt",argv[1]);
        }else{
            titleSequence("assets/title.txt","color D");
        }
        switch(inputCode = getANS()){

            case 1:
                GameLoop(&endState); 
                break;

            case 2:
                system("cls");
                returnIMG("assets/help.txt");
                getANS();
                break;
            
            case 4:
                system("cls");
                titleSequence("assets/title.txt","color D");
                break;
            
            default:
                break;
        }


    }




}
