//
// Created by Jacinto Gomez on 3/7/24.
//

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> v2d;
typedef vector<int> v1d;

void print(const v2d& v){
    for(const v1d& i:v){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void fillv(v2d input,v2d &output){
    for(int i=0;i<input.size();i++){
        for(int j=0;j<input[i].size();j++){
            output[i][j]=input[i][j];
        }
    }
}

int main() {
    int count=1,dim=3;
    v2d input,output;
    for(int i=0;i<dim;i++){
        v1d temp;
        for(int j=0;j<dim;j++){
            temp.push_back(count);
            count++;
        }
        output.push_back(temp);
    }
    fillv(input,output);
    print(output);
}
