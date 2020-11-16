#include <iostream>
using namespace std;
int dp[50];
int fibo(int num) {
	if (num == 0) return num;
	if (num == 1) return num;
    
	if (dp[num] != 0) {
		return dp[num];
	}
	else {
		dp[num] = fibo(num - 1) + fibo(num - 2);
		return dp[num];
	}
}
int main() {
	int n = 0;
	cin >> n;
	cout << fibo(n) ;
	
}
