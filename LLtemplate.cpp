//
// Created by Jacinto Gomez on 6/20/23.
//

#include <iostream>
#include <string>
using namespace std;

template<class T>
class node {
public:
    node(T val){  //constructor
        this->prev=this->next=nullptr;
        this->val=val;
    }
    T val;
    node<T> *prev;
    node<T> *next;
};

template<class T>
class list{
public:
    node<T>* head;
    node<T>* tail;
    int size;
    list(){ //no-arg constructor
        this->head=this->tail=nullptr;
        size=0;
    }
    list(node<T>* input){ //constructor
        this->head=input;
        this->tail=input;
        this->size=1;
    }
    void addend(node<T>* end){
        this->tail->next=end;
        end->prev=this->tail;
        this->tail=end;
        this->size++;
    }
    void addbeginning(node<T>* begin){
        this->head->prev=begin;
        begin->next=this->head;
        this->head=begin;
        this->size++;
    }
    void removeend(){
        if(this->size==0){cout<<"Cannot remove from empty list"<<endl;return;}
        node<T>* oldtail=this->tail;
        this->tail=this->tail->prev;
        if(this->tail!=nullptr){this->tail->next=nullptr;}
        delete oldtail;
        this->size--;
    }
    void removebeginning(){
        if(this->size==0){cout<<"Cannot remove from empty list"<<endl;return;}
        node<T>* oldhead=this->head;
        this->head=this->head->next;
        if(this->head!=nullptr){this->head->prev=nullptr;}
        delete oldhead;
        this->size--;
    }
    void print(){
        if(this->size==0){cout<<"List is empty"<<endl;return;}
        node<T>* on=this->head;
        while(on!=nullptr){
            cout<<on->val<<" ";
            on=on->next;
        }
        cout<<endl;
    }
    void deallocate(){
        node<T> *start=this->head,*temp;
        while(start!=nullptr){
            cout<<"titties";
            if(temp!=tail){temp=start->next;}
            cout<<start->val;
            delete start; //delete memory
            start=nullptr; //prevent dangling pointer
        }
    }
};

int main(){
    cout<<"Linked list initialized with one element"<<endl;
    auto* start=new node<string>("Tandon");
    auto* dl=new list<string>(start);
//    dl->print();
//    dl->removebeginning();
//    dl->print();
//    dl->removeend();
//    dl->print();
    cout<<endl<<"add another element to the end"<<endl;
    auto* one=new node<string>("Stern");
    dl->addend(one);
    dl->print();

    cout<<endl<<"add another element to the beginning"<<endl;
    auto* two=new node<string>("Silver");
    dl->addbeginning(two);
    dl->print();

    cout<<endl<<"add 3 more to the end"<<endl;
    auto* three=new node<string>("Courant");
    auto* four=new node<string>("Wagner");
    auto* five=new node<string>("Tisch");
    dl->addend(three);
    dl->addend(four);
    dl->addend(five);
    dl->print();

    cout<<endl<<"remove the last element"<<endl;
    dl->removeend();
    dl->print();

    cout<<endl<<"remove the first element"<<endl;
    dl->removebeginning();
    dl->print();
    dl->deallocate();
    delete dl;
    return 0;
}