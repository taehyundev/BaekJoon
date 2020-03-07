#include <iostream>
#include <string>
using namespace std;

int month, day;
string d[7] = { "SUN","MON", "TUE", "WED", "THU", "FRI", "SAT" };
void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}
int search(int i, int max) {
	int temp;
	for (int j= 1; j <= max; j++) {
		temp = j;
		if (i == month && j == day) {
			break;
		}
	}
	return temp;
}
int main() {
	//Default : 2007 1 1 는 MON
	init();

	cin >> month >> day;
	
	int sum = 0;

	for (int i = 1; i <= month; i++) {

		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			sum += search(i, 31);
		else if (i == 2)
			sum += search(i, 28);
		else
			sum += search(i, 30);
	}
	cout << d[(sum%7)];
}
