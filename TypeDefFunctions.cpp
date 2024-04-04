//
// Created by Jacinto Gomez on 3/8/24.
//

#include <iostream>
using namespace std;

//We need to declare a new type
typedef int (*ptrfunc)(int);
typedef void (*msgfunc)(int,int);

int addone(int x){
    return x+1;
}

//This is a function that returns a pointer to another function
ptrfunc dotask(){
    return addone; //The function returned here is addone
}

void add(int x,int y){
    cout<<x<<" + "<<y<<" = "<<x+y<<endl;
}

void subtract(int x,int y){
    cout<<x<<" - "<<y<<" = "<<x-y<<endl;
}

void multiply(int x,int y){
    cout<<x<<" * "<<y<<" = "<<x*y<<endl;
}

void divide(int x,int y){
    cout<<x<<"  "<<y<<" = "<<x/y<<endl;
}

void modulo(int x,int y){
    cout<<x<<" mod "<<y<<" = "<<x%y<<endl;
}

int main(){
    //Define a new pointer function ptrf, which is defined as the dotask() function
    ptrfunc ptrf=dotask();
    cout<<ptrf(100)<<endl;
    //^Very simple example

    //More useful application: creating a list of functions to call all of them
    cout<<"Enter 2 numbers: ";
    int x,y;
    cin>>x>>y;
    msgfunc functionarray[]={add,subtract,multiply,divide,modulo};
    for(msgfunc printthis:functionarray){
        printthis(x,y);
    }
    return 0;
}