//
// Created by Jacinto Gomez on 5/13/24.
//

#include <iostream>
#include <fstream>
using namespace std;

class node{
public:
    node(int d):dig(d){}
    int dig;
    node* next=nullptr;
    node* prev=nullptr;
};

class list{
public:
    node* head=nullptr;
    node* tail=nullptr;
    int size;
    string name; //filename
    list(string fn):name(fn),size(0){}
    void append(node* n){
        if(size==0){
            head=tail=n;
        }else{
            tail->next=n;
            n->prev=tail;
            tail=n;
        }
        size++;
    }
    void prepend(node* n){
        if(size==0){
            head=tail=n;
        }else{
            head->prev=n;
            n->next=head;
            head=n;
        }
        size++;
    }
    void add(list* one,list* two){
        node* t1=one->tail;
        node* t2=two->tail;
        int sum,tens=0,remainder;
        while(t1!=nullptr&&t2!=nullptr){
            sum=t1->dig+t2->dig+tens;
            tens=sum/10;
            remainder=sum%10;
            node* temp=new node(remainder);
            this->prepend(temp);
            t1=t1->prev;
            t2=t2->prev;
        }
        while(t1!=nullptr){
            sum=t1->dig+tens;
            tens=sum/10;
            node* temp=new node(sum);
            this->prepend(temp);
            t1=t1->prev;
        }
        while(t2!=nullptr){
            sum=t2->dig+tens;
            tens=sum/10;
            node* temp=new node(sum);
            this->prepend(temp);
            t2=t2->prev;
        }
        if(tens>0){
            node* temp=new node(tens);
            this->prepend(temp);
        }
    }
    void readin(ifstream& f){
        string line;
        while(getline(f,line)){
            for(char digit:line){
                node* n=new node(digit-'0');
                this->append(n);
            }
        }
    }
    void writeout(ofstream& f){
        node* temp=head;
        while(temp!=nullptr){
            f<<temp->dig;
            temp=temp->next;
        }
        f<<endl;
    }
    void openinputfile(ifstream& infile){
        infile.open(name);
        while(!infile){
            cout<<"Failed to open'\n'Make sure you are entering the proper name";
            cin>>name;
            infile.clear();
            infile.open(name);
        }
    }
    void closeinputfile(ifstream& infile){
        infile.close();
    }
    void openoutputfile(ofstream& outfile){
        outfile.open(name);
        while(!outfile){
            cout<<"Failed to open'\n'Make sure you are entering the proper name";
            cin>>name;
            outfile.clear();
            outfile.open(name);
        }
    }
    void closeoutputfile(ofstream& outfile){
        outfile.close();
    }
    void display(){
        cout<<name<<": ";
        node* temp=head;
        while(temp!=nullptr){
            cout<<temp->dig;
            temp=temp->next;
        }
        cout<<endl;
    }
    void display_backwards(){
        cout<<name<<": ";
        node* temp=tail;
        while(temp!=nullptr){
            cout<<temp->dig;
            temp=temp->prev;
        }
        cout<<endl;
    }
};

int main(){
    ifstream if1,if2;
    ofstream of3;
    list* l1=new list("num1.txt");
    l1->openinputfile(if1);
    l1->readin(if1);
    l1->display();
    l1->closeinputfile(if1);

    list* l2=new list("num2.txt");
    l2->openinputfile(if2);
    l2->readin(if2);
    l2->display();
    l2->closeinputfile(if2);

    list* l3=new list("num3.txt");
    l3->add(l1,l2);
    l3->display();
    l3->openoutputfile(of3);
    l3->writeout(of3);
    l3->closeoutputfile(of3);
    return 0;
}
