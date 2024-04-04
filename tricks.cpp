#include <iostream>
using namespace std;

int main(){
    int x=234,y=89;
    cout<<"x is "<<x<<" and y is "<<y<<endl;
    //swap two ints without using a temp variable
    x^=y;
    y^=x;
    x^=y;
    cout<<"x is "<<x<<" and y is "<<y<<endl;

    //is number even or odd?
    int num=345;
    (num%2==0)?cout<<"even"<<endl:cout<<"even"<<endl;
    (num&1)?cout<<"even"<<endl:cout<<"even"<<endl;

    //shorter single if statement
    if(num==345){
        cout<<"it is"<<endl;
    }
    num==345&&cout<<"it is"<<endl;

    return 0;
}