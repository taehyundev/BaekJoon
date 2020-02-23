#include <iostream>
#include <algorithm>
using namespace std;
int datan[5000000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, n1;
	cin >> n >> n1;
	
	for (int i = 0; i < n; i++) {
		cin >>datan[i];
	}
	sort(datan, datan + n);
	cout << datan[n1 - 1];
}