#include <stack>
#include <iostream>
using namespace std;
int main() {
	int n;
	int x;
	stack<int> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			s.pop();
		}
		else {
			s.push(x);
		}
	}
	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}
	cout << sum;
}