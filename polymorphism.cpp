//
// Created by Jacinto Gomez on 5/6/24.
//

#include <iostream>
using namespace std;

class Animal{
public:
    Animal(int l,string n):legs(l),name(n){}
    int legs;
    string name;
    // Either of the below work for makesound, but if it is not pure virtual it needs a definition
    virtual void makesound()=0;
    //virtual void makesound(){cout<<"no speficied sound"<<endl;}
};

class Dog:public Animal{
public:
    Dog(string b,string n):Animal(4,n),breed(b){}
    string breed;
    void makesound(){cout<<"Woof"<<endl;}
};

class Otter:public Animal{
public:
    Otter(bool t,string n):Animal(4,n),issea(t){}
    bool issea; //true for sea otter, false for river otter
    void makesound(){cout<<"Squeak"<<endl;}
};

int main(){
    Otter kira(true,"Kira");
    Dog max("Husky","Max");
    // Animal animal(4,"nobody"); Cannot instantiate an abstract class
    cout<<"Sounds made by Dog and Otter"<<endl;
    max.makesound();
    kira.makesound();

    cout<<"Dynamic binding on a generic Animal pointer (must be a pointer, cannot make a real Animal object)"<<endl;
    Animal *ptr; // But you can make a reference to an abstract class, and give it the address of an object
    ptr=&kira;
    ptr->makesound(); // This is dynamic binding, where the function behaves differently depending on what type of object it is called on
    return 0;
}