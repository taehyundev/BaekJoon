#include <iostream>
#include <cstdio>
using namespace std;
long long dp[91] = { 0, };
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= 90; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int n;
	cin >> n;
	cout <<dp[n];
}