#include <iostream>
#include <vector>
using namespace std;

//this class is for the auto example just ignore it
class ComplexThing{
public:
    ComplexThing(int n):member(n){}
    int member;
};

int main(){
    //initializing variables for examples
    int x=234,y=89,num=345;
    ComplexThing object(5);
    vector<ComplexThing> vec1={object,object,object,object};

    //-----------------------------------------------------

    cout<<"x is "<<x<<" and y is "<<y<<endl;
    //swap two ints without using a temp variable
    x^=y;
    y^=x;
    x^=y;
    cout<<"x is "<<x<<" and y is "<<y<<endl;

    //-----------------------------------------------------

    //is number even or odd?
    (num%2==0)?cout<<"even"<<endl:cout<<"even"<<endl; //<- ternary operator
    (num&1)?cout<<"even"<<endl:cout<<"even"<<endl;

    //-----------------------------------------------------

    //shorter single if statement
    if(num==345){
        cout<<"it is"<<endl;
    }
    num==345&&cout<<"it is"<<endl;

    //-----------------------------------------------------

    //auto keyword
    ComplexThing* example1=new ComplexThing(7);
    auto example2=new ComplexThing(8);

    vector<ComplexThing*> vec2={example1,example2};
    for(ComplexThing* element:vec2){
        cout<<element->member<<" ";
    }cout<<endl;
    for(auto element:vec2){
        cout<<element->member<<" ";
    }cout<<endl;

    return 0;
}