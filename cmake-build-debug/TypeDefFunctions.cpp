//
// Created by Jacinto Gomez on 3/8/24.
//

#include <iostream>
using namespace std;

//We need to define a new type
typedef int (*ptrfunc)(int);

int addone(int x){
    return x+1;
}

//This is a function that returns a pointer to another function
ptrfunc dotask(){
    return addone; //The function returned here is addone
}

int main(){
    //Define a new pointer function ptrf, which is defined as the dotask() function
    ptrfunc ptrf=dotask();
    cout<<ptrf(100);
    return 0;
}