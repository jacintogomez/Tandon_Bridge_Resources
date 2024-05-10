//
// Created by Jacinto Gomez on 5/9/24.
//
/* I saw a question once that was something like "a group of people are numbered and holding hands in a circle
 * and every nth person is eliminated. What is the # of the last person standing?"
 * The answer to this will depend on:
 *  n - the # of people skipped
 *  x - the # of people who started
 * We can answer this easily with a circular implementation of a linked list
*/

#include <iostream>
using namespace std;

class num{
public:
    num(int v):val(v){}
    int val;
    num* next=nullptr;
    num* prev=nullptr;
};

class circle{
public:
    int size;
    num *head,*tail;
    circle(){
        head=tail=nullptr;
        size=0;
    }
    void addin(num* s){ //add a node between the head and tail
        if(size==0){
            head=tail=s;
            head->next=head->prev=tail;
            tail->next=tail->prev=head;
        }else{
            tail->next=s;
            head->prev=s;
            s->next=head;
            s->prev=tail;
        }
        size++;
    }
    void fill(int t){
        for(int x=1;x<=t;x++){
            num* node=new num(x);
            this->addin(node);
        }
    }
    int eliminate(int e){
    }
    void deallocate(){
        num *begin=head,*temp;
        while(begin!=nullptr){
            if(temp!=tail){temp=begin->next;}
            delete begin;
            begin=nullptr;
        }
    }
};

int main(){
    int target,separation;
    cout<<"How many people in the ring? ";
    cin>>target;
    cout<<"How many people will be skipped each turn? ";
    cin>>separation;
    circle* ring=new circle(); //could also do auto* ring=new circle();
    ring->fill(target);
    int last_standing=ring->eliminate()->val;

    // Cleaning dynamic memory below
    ring->deallocate(separation);
    delete ring;
    return 0;
}