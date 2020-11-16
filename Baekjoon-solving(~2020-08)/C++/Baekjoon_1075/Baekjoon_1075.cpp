//가장 뒤 두자리 변경

#include <iostream>
using namespace std;
int main() {
	int N, F;
	int i;
	cin >> N >> F;
	N = (N / 100) * 100;

	for (i = 0; i < 100; i++) {
		int temp = N + i;
		if (temp % F == 0) {
			break;
		}
	}
	if (i < 10) {
		cout << "0" << i;
	}
	else {
		cout << i;
	}
}
