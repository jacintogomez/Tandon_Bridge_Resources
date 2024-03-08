//
// Created by Jacinto Gomez on 3/7/24.
//

#include <iostream>
#include <array>
using namespace std;

void print(int *ar){
    for(int i=0;i<5;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}

void eve1(int (&ar)[5],int s){
    for(int i=0;i<s;i++){
        ar[i]*=2;
    }
}

void eve2(int *ar,int s){
    for(int i=0;i<s;i++){
        ar[i]*=2;
    }
}

void eve3(array<int,5> &ar){
    for(int &i:ar){
        i*=2;
    }
}

void eve4(int *ar,int s){
    for(int i=0;i<s;i++){
        ar[i]*=2;
    }
}

int main() {
    int ar[5]={1,2,3,4,5};
    eve1(ar,5);
    print(ar);
    eve2(ar,5);
    print(ar);
    array<int,5> ra={3,4,5,4,3};
    eve3(ra);
    for(int i:ra){cout<<i<<" ";}
    return 0;
}
