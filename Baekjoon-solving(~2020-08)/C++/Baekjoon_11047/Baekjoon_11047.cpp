#include <iostream>
using namespace std;
int main() {
	int n, k;
	int money_num = 0;
	cin >> n>>k;
	int * a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	
		for (int i = 1; i <= n; i++) {
			if (k - a[n - i] > -1) {
				money_num += k / a[n - i];
				k -= (k / a[n - i]) * a[n - i];
			}

		}
	cout << money_num;

}