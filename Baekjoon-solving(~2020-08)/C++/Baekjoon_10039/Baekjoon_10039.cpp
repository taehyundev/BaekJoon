#include <iostream>
#define MAX 5
using namespace std;
int datan[5];
int main() {
	int sum = 0;
	for (int i = 0; i < MAX; i++) {
		cin >> datan[i];
		if (datan[i] <= 40) {
			datan[i] = 40;
		}
		sum += datan[i];
	}
	cout << sum / MAX;
}
