#include <iostream>
#define MAX 5
using namespace std;

int datan[MAX];

int main() {
	int minBuger = 2001;
	int minDrink = 2001;
	for (int i = 0; i < MAX; i++) {
		cin >> datan[i];
		if (0 <= i && i <= 2) {
			if (minBuger > datan[i]) minBuger = datan[i];
		}
		else {
			if (minDrink > datan[i]) minDrink = datan[i];
		}
	}

	int set = (minBuger + minDrink) - 50;
	cout << set;
}
