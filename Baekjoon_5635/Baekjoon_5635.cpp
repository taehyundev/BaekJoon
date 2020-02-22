#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string name;
	int year;
	int month;
	int day;
	int date;

	int max;
	int min;

	string max_n;
	string min_n;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> day >> month >> year;
		date = year * 10000 + (month * 100) + day;
		if (i == 0) {
			max = date;
			min = date;
			max_n = name;
			min_n = name;
		}
		else {
			if (max < date) {
				max = date;
				max_n = name;
			}
			if (min > date) {
				min = date;
				min_n = name;
			}
		}

	}

	cout << max_n << "\n" << min_n;

}
