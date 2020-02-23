#include <iostream>
#include <algorithm>
using namespace std;
int rankn[51];
int main() {
	int n,m, p; //p는 랭킹리스트에 올라갈 수 있는 점수의 개수
	cin >> n>>m>>p;
	for (int i = 0; i < n; i++) {
		cin >> rankn[i];
	}
	int cnt = 1;

	if (n == p && rankn[n - 1] >= m) {
		cnt = -1;
	}
	else {
		for (int i = 0; i < n; i++) {
			if (rankn[i] > m) {
				cnt++;
			}
		}
	}


	cout << cnt;
}