#include <iostream>

using namespace std;

int main() {
    int A, B, V;
    cin>>A>>B>>V;
    if(A == V)
        cout<<1;
    else{
        int answers = 0;
        int C = V-A;
        int D = A-B;
        int E = C/D;
        if((double)E != (double)C/(double)D)
            answers = E+2;
        else
            answers = E+1;
        
        cout<<(int)answers;
    }
}