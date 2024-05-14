//
// Created by Jacinto Gomez on 5/12/24.
//

#include <iostream>
#include <vector>
using namespace std;

class Base{
public:
    Base(){}
    virtual void f(){cout<<"Base"<<endl;}
};

class Derived:public Base{
public:
    Derived():Base(){}
    virtual void f(){cout<<"Derived"<<endl;}
};

int main(){
    vector<Base> bases;

    Base o1=Derived();
    Derived o2=Derived();
    Base o3=Base();

    bases.push_back(o1);
    bases.push_back(o2);
    bases.push_back(o3);

    for(Base bo:bases){
        bo.f();
    }

    o1.f();
    o2.f();
    o3.f();

    return 0;
}
