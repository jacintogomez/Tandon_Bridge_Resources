//
// Created by Jacinto Gomez on 3/8/24.
//

#include <iostream>
using namespace std;

//We need to define a new type
typedef int (*ptrfunc)(int);
typedef void (*msgfunc)();

int addone(int x){
    return x+1;
}

//This is a function that returns a pointer to another function
ptrfunc dotask(){
    return addone; //The function returned here is addone
}

void m1(){cout<<"Hello ";}
void m2(){cout<<"how ";}
void m3(){cout<<"are you?";}

int main(){
    //Define a new pointer function ptrf, which is defined as the dotask() function
    ptrfunc ptrf=dotask();
    cout<<ptrf(100)<<endl;
    //^Very simple example

    //More useful application: creating a list of functions to call all of them
    msgfunc functionarray[]={m1,m2,m3};
    for(msgfunc printthis:functionarray){
        printthis();
    }
    return 0;
}