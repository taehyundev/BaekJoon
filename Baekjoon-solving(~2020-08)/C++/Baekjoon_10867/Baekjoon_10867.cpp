#include <cstdio>
#include <algorithm>
using namespace std;
int map[100001];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &map[i]);
	}
	sort(map, map + n);
	int m = map[0];
	printf("%d ", m);
	for (int i = 1; i < n; i++) {
		if (map[i] !=m) {
			printf("%d ", map[i]);
			m = map[i];
		}
	}
}