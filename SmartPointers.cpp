// Created by Jacinto Gomez on 3/4/24.

//4 types of smart pointers:
//1. auto - deprecated so don't use this anymore, was replaced by unique
//2. unique - only allows 1 pointer to a resource; if another pointer tries to point to it
//3. shared - allow multiple pointers to a resource; use_count keeps track of how many pointers are shared in it
//4. weak - observe resource without affecting ownership; cannot directly access the weak pointer

#include <iostream>
using namespace std;

class Shape{
public:
    Shape(string n,int s):name(n),sides(s){}
    string name;
    int sides;
    void degrees(){cout<<(sides-2)*180<<"º"<<endl;}
};

void weakpointers(){
    cout<<endl<<"Weak Smart Pointers"<<endl;
    shared_ptr<Shape> oct(new Shape("Octagon",8));
    weak_ptr<Shape> octref=oct;
    oct->degrees();
    if(auto locked=octref.lock()){locked->degrees();}
    else{cout<<"Shared object was deleted";}
    cout<<oct.use_count()<<endl;
}

void sharedpointers(){
    cout<<endl<<"Shared Smart Pointers"<<endl;
    shared_ptr<Shape> hex(new Shape("Hexagon",6));
    shared_ptr<Shape> hexcopy=hex;
    hex->degrees();
    hexcopy->degrees();
    cout<<hex.use_count()<<" "<<hexcopy.use_count()<<endl;
}

void uniquepointers(){
    cout<<"Unique Smart Pointers"<<endl;
    unique_ptr<Shape> pent(new Shape("Pentagon",5));
    pent->degrees();
    unique_ptr<Shape> pentremake;
    pentremake=move(pent);
    pentremake->degrees();
    //pent->degrees();  <- this will cause a segmentation fault
}

int main(){
    uniquepointers();
    sharedpointers();
    weakpointers();
    return 0;
}
