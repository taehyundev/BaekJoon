/*
input
5
5
2
3
4
1
*/
#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    init();
    int n;
    cin >>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    
    for(int i=0;i<n;i++){
        cout << arr[i]<<"\n";
    }
    
}