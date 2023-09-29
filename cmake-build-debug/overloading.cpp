#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    Person(string fn,string ln,int a,bool g):firstname(fn),lastname(ln),age(a),gender(g){}
    string firstname;
    string lastname;
    bool gender;
    int age;
    Person* spouse=nullptr;
    void marriage(Person* partner){
        this->spouse=partner;
        partner->spouse=this;
        if(this->gender=='f'&&partner->gender=='m'){
            this->lastname=partner->lastname;
        }else if(this->gender=='m'&&partner->gender=='f'){
            partner->lastname=this->lastname;
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

//void marriage(Person* man,Person* woman)


int main(){
    Person jack("Jacinto","Rigal",25,1);
    Person yuri("Yoojung","Kang",47,0);
    cout<<jack<<yuri;
    return 0;
}