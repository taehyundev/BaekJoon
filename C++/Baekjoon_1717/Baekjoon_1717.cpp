#include <iostream>
using namespace std;

int parent[1000001];

int getFind(int n) {
	if (parent[n] == n) return n; // 부모를 return
	int m = getFind(parent[n]);
	parent[n] = m;
	return m;

}
void setUnion(int x, int y) {
	x = getFind(x);
	y = getFind(y);
	if (x != y) {
		parent[y] = x;
	}
}

void init() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

int main() {
	init();

	int V;
	int T;
	cin >> V >> T;

	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < T; i++) {
		int oper, x, y;
		cin >> oper >> x >> y;
		if (oper == 0) {
			setUnion(x, y);
		}
		else {
			if (getFind(x) == getFind(y)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}


}
