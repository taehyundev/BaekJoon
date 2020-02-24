#include <iostream>
#include <string.h>
using namespace std;
int main() {
	string str;
	cin >> str;
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		
		cout << str[i];
		cnt++;
		if (cnt % 10 == 0) {
			cout << endl;
		}
	}
}
