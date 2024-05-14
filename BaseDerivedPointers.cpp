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
    void s(){cout<<"(Special)"<<endl;}
};

int main(){
    vector<Base*> bases;

    Base *o1=new Derived();
    Derived *o2=new Derived();
    Base *o3=new Base();

    bases.push_back(o1);
    bases.push_back(o2);
    bases.push_back(o3);

    for(Base *bo:bases){
        bo->f();
    }

    o1->f();
    o2->f(); //we can also call ->s() here, but cannot call ->s() above on o1 since we declared it as a Base pointer
    o3->f();

    delete o1;
    delete o2;
    delete o3;

    return 0;
}
