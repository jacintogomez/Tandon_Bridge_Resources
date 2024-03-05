//
// Created by Jacinto Gomez on 3/5/24.
//

#include <iostream>
using namespace std;

void ampersand(int &x){
    x+=100;
}

void star(int *x){
    *x+=100;
}

//void starampersand(int *&x){

void doublestar(int **x){
    **x+=100;
}

int main(){
    int origin=1;
    int v1=origin,*v2=&origin,**v4=&v2;
    ampersand(v1);
    cout<<"Result of pass by reference (int &x): "<<v1<<endl;
    star(v2);
    cout<<"Result of passing a pointer (int *x): "<<*v2<<endl;
    doublestar(v4);
    cout<<"Result of passing a double pointer (int **x): "<<**v4<<endl;
    return 0;
}