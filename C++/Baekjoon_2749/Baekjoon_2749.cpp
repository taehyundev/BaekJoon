#include <iostream>
using namespace std;
long long num[1500000];
int INF = 1000000;
void solve() {
	num[0] = 0;
	num[1] = 1;
	for (int i = 0; i < 1500000; i++) {
		num[i + 2] = (num[i + 1] + num[i]) % INF;
	}

}
int main() {
	long long n;
	cin >> n;
	solve();
	cout << num[n % 1500000] << endl;
}

//피사노주기 https://www.acmicpc.net/problem/9471 참조
