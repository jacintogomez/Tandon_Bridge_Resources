#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    Person(string fn,string ln,int a,string g):firstname(fn),lastname(ln),age(a),gender(g){}
    string firstname;
    string lastname;
    string gender;
    int age;
    Person* spouse=nullptr;
    void marriage(Person* partner){
        if(this->spouse!=nullptr||partner->spouse!=nullptr){ //make sure both are unmarried
            cout<<this->firstname<<" and "<<partner->firstname<<" cannot be married."<<endl;
            return;
        }
        this->spouse=partner;
        partner->spouse=this; //"this" is a pointer to the current object
        //not necessary but just putting last name changing in as a further example of data processing
        if(this->gender=="female"^partner->gender=="female"){ //^ is the xor operator
            (this->gender=="female")?this->lastname=partner->lastname:partner->lastname=this->lastname; //the ? and : are part of the ternary operator
        }
    }
    friend ostream& operator<<(ostream& os,const Person& x){
        Person* s=x.spouse;
        os<<x.firstname<<" "<<x.lastname<<" is a "<<x.age<<" year old "<<x.gender;
        if(s!=nullptr){os<<", and is married to "<<s->firstname<<" "<<s->lastname;}
        os<<endl;
        return os;
    }
};

void marriage(Person* a,Person* b){ //same function as above, but not a class member
    if(a->spouse!=nullptr||b->spouse!=nullptr){
        cout<<a->firstname<<" and "<<b->firstname<<" cannot be married."<<endl;
        return;
    }
    a->spouse=b;
    b->spouse=a;
    if(a->gender=="female"^b->gender=="female"){
        (a->gender=="female")?a->lastname=b->lastname:b->lastname=a->lastname;
    }
}

int main(){
    cout<<"We start with our two people: "<<endl;
    Person jack("Jack","Johnson",30,"male");
    Person mandy("Amanda","Smith",30,"female");
    cout<<jack<<mandy;
    cout<<endl<<"After performing the marriage operation on them they become: "<<endl;
    jack.marriage(&mandy);
    cout<<jack<<mandy;
    cout<<endl<<"Now lets try with two different people: "<<endl;
    Person jill("Jillian","Roberts",27,"female");
    Person charlie("Charles","Smith",28,"male");
    cout<<jill<<charlie;
    cout<<endl<<"We can still perform the operation on these objects, but this time using a non-member function: "<<endl;
    marriage(&jill,&charlie);
    cout<<jill<<charlie;
    return 0;
}