#include <iostream>
#include <vector>
using namespace std;
int parent[1001];
int __find(int n) {
	if (parent[n] == n)
		return n;
	else {
		int m = __find(parent[n]);
		parent[n] = m;
		return m;
	}
}



void __union(int x, int y) {
	x = __find(x);
	y = __find(y);

	if (x != y) {
		parent[y] = x;
	}
}

int main() {
	int n, n1;
	int vertax;
	cin >> n >> n1;
	vector<int> compareGoal(n1);
	//parent 초기화
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> vertax;
			if (vertax == 1) {
				__union(i, j);
			}
		}
	}
	bool equalsUnion = true;
	for (int i = 0; i < n1; i++) {
		cin >> compareGoal[i];
		compareGoal[i] = __find(compareGoal[i]);
	}
	int temp = compareGoal[0];
	for (int i = 1; i < n1; i++) {
		if (temp != compareGoal[i]) {
			equalsUnion = false;
			break;
		}
	}
	if (equalsUnion) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

}