//
// Created by Jacinto Gomez on 5/9/24.
//
/* I saw a question once that was something like "a group of people are numbered and holding hands in a circle
 * and every nth person is eliminated. What is the # of the last person standing?"
 * The answer to this will depend on:
 *  n - the # of people skipped
 *  x - the # of people who started
 * We can answer this easily with a circular implementation of a linked list
 * Behavior: Starting at 1, count off n people then eliminate person n
 * Example: n=5, x=1, start at #1, skip 1 person (#2) and eliminate #3. Then start at #3, skip 1 person (#4) and eliminate #5
*/

#include <iostream>
#include <vector>
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
    vector<num*> allnums;
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
            tail=s;
        }
        size++;
    }
    void fill(int t){
        for(int x=1;x<=t;x++){
            num* node=new num(x);
            this->addin(node);
            allnums.push_back(node);
        }
    }
    void takeout(num* e){
        if(e==head){head=e->next;}
        e->prev->next=e->next;
        e->next->prev=e->prev;
        size--;
    }
    void display(){
        cout<<"{{ ";
        num* temp=head;
        do{
            cout<<temp->val<<' ';
            temp=temp->next;
        }while(temp!=head&&size>1);
        cout<<"}}"<<endl;
    }
    num* iterate_to(int s){
        num* temp=head;
        for(int x=1;x<s;x++){
            temp=temp->next;
        }
        return temp;
    }
    num* eliminate(int e,int s){
        num* pin=iterate_to(s);
        while(size>1){
            for(int x=0;x<=e;x++){
                pin=pin->next;
            }
            takeout(pin);
            //display();
        }
        return pin->next;
    }
    void deallocate(){
        for(num* n:allnums){
            delete n;
            n=nullptr;
        }
    }
};

int main(){
    int target,separation,start;
    cout<<"How many people in the ring? ";
    cin>>target;
    cout<<"How many people will be skipped each turn? ";
    cin>>separation;
    cout<<"Which person will the counting start on? (default is 1)";
    cin>>start;
    if(start>target||start<=0){
        cout<<"Non-existent starting person. Will start at #1 instead"<<endl;
        start=1;
    }
    circle* ring=new circle(); //could also do auto* ring=new circle();
    ring->fill(target);
    //ring->display();
    int last_standing=ring->eliminate(separation,start)->val;
    cout<<"The last person standing is #"<<last_standing;

    // Cleaning dynamic memory below
    ring->deallocate();
    delete ring;
    return 0;
}