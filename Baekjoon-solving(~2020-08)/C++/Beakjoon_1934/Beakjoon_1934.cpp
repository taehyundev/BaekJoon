#include <iostream>
using namespace std;
class gcd {
private:
	int x, y;
	int Remainder;
	int value;
public:
	gcd(int a, int b);
	int Euclid();
};
gcd::gcd(int a, int b) {
	if (a >= b) { x = a; y = b; }
	else if (a < b) { x = b; y = a; }
}
int gcd::Euclid() {
	do {
		Remainder = x % y;
		value = x / y;
		x = y;
		y = Remainder;
	} while (Remainder != 0);
	return x;
}

int main() {
	int x, y;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		gcd gcd(x, y);
		int gcd_value = gcd.Euclid();
		cout << x*y/gcd_value << endl;
	}
}
