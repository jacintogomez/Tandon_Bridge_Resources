#include <cassert>
using namespace std;

int n(int);

int main() {
    int j=n(7);
    cout<<j;
    assert(j==3);
    return 0;
}

int n(int i){
    return i*7;
}
