#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

std::string version = "";

void buildApp(){
    std::string temp ="unzip " + version + ".zip"; 
    system(temp.c_str());
    temp = "cd ./godemon-" + version;
    system(temp.c_str());
    system("go build");
}

void prepareDirs(){
    system("mkdir ~/.godemon");
    system("mkdir ~/.godemon/logs/");
    system("mkdir ~/.godemon/bin/");
}

void removing(){
    system("cd ..");
    std::string temp = "sudo rm -r godemon-"+ version;
    system(temp.c_str());
    temp = "sudo rm -r "+version+".zip";
    system(temp.c_str()); 
}

int main(){
    int GL=0;
    std::cout<<"*************__*************\n************/*/*************\n***********/*/**************\n**********/*/____***********\n*********/____**/***********\n*************/*/************\n************/*/*************\n***********/*/**************\n**********/*/***************\n*********/_/****************\n****************************\n"; 
    std::cout<<"\nWhat version do you want to install: ";
    std::cin>>version;
    std::cout<<"\nDo you want to do this: \n1. Global \n2. Local \n";
    std::cout<<"\nAnswer: ";
    std::cin>>GL;

    std::string temp = "wget https://github.com/nProgrammer/godemon/archive/"+version+".zip";
    system(temp.c_str());
    if(GL==2){
        buildApp();
        prepareDirs();
        system("sudo mv godemon ~/.godemon/bin/");
        system("sudo chmod 777 ~/.godemon/bin/godemon");
        removing();
    }
    else if(GL==1){
        buildApp();
        prepareDirs();
        system("sudo mkdir /usr/local/.godemon/bin/");
        system("sudo mv godemon /usr/local/.godemon/bin/");
        system("sudo chmod 777 /usr/local/.godemon/bin/godemon");
        removing();
    }
    std::cout<<"Everything done"<<std::endl;
    return 0;
}