#include <cstdio>
#include <algorithm>
using namespace std;
int map[1000001];

int main() {
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &map[i]);
	}
	sort(map, map + n);
	for (int i = 0; i < n; i++) {
		printf("%d\n", map[i]);
	}
}