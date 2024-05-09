//
// Created by Jacinto Gomez on 5/8/24.
//

#include <iostream>
using namespace std;

class person{
public:
    person(string n,int a):name(n),age(a){}
    string name;
    int age;
    person* next=nullptr;
};

class list{
public:
    person *head,*tail;
    int size;
    list(){
        head=tail=nullptr;
        size=0;
    }
    void addend(person* p){
        if(size==0){
            head=tail=p;
            size++;
            return;
        }
        this->tail->next=p;
        this->tail=p;
        size++;
    }
    void addbeginning(person* p){
        if(size==0){
            head=tail=p;
            size++;
            return;
        }
        p->next=this->head;
        this->head=p;
        size++;
    }
    void print(){
        person* start=this->head;
        while(start!=nullptr){
            cout<<"Name: "<<start->name<<", Age: "<<start->age<<endl;
            start=start->next;
        }
    }
    void deallocate(){
        person *start=this->head,*temp;
        while(start!=nullptr){
            if(temp!=tail){temp=start->next;}
            delete start; //delete memory
            start=nullptr; //prevent dangling pointer
        }
    }
};

int main(){
    list* l=new list();
    l->addend(new person("Dalton",24));
    l->addend(new person("John",32));
    l->addbeginning(new person("Jack",25));
    l->print();
    l->deallocate();
    delete l;
    return 0;
}