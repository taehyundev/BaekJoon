#include <iostream>
using namespace std;

int reverseInt(int n) {
	int a, b, c;
	a = n / 100;
	b = (n - (a * 100)) / 10;
	c = n - (a * 100) - (b * 10);
	n = a + (b * 10) + (c * 100);
	
	return n;
}

int main() {
	int n, n1;
	cin >> n >> n1;
	n=reverseInt(n);
	n1 = reverseInt(n1);

	if (n > n1) {
		cout << n;
	}
	else {
		cout << n1;
	}

}
