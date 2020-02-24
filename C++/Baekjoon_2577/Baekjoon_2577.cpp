#include <iostream>
using namespace std;
int main() {
	int a, b, c;
	int arr[10] = { 0, };
		int result;
	cin >> a >> b >>c;
	result = a * b * c;
	while (result > 0) {
		arr[result % 10] ++;
		result = result / 10;
	}
	
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}

}