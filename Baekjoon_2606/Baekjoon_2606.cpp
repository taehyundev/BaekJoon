#include <iostream>
#include <queue>
using namespace std;
int graph[1000][1000] = { 0, };
int bfs_visit[1000] = { 0, };
int dfs_visit[1000] = { 0, };

int vertax;
int cnt = 0;

void bfs(int v) {
	bfs_visit[v] = 1;
	queue<int> q;
	q.push(v);
	while (!q.empty()) {
		v = q.front();
		q.pop();
		for (int i = 1; i <= vertax; i++) {
			if (bfs_visit[i] == 0 && graph[v][i] == 1) {
				bfs_visit[i] = 1;
				cnt++;
				q.push(i);
			}
		}
	}
	cout << cnt;
}

int main() {
	int edge;
	cin >> vertax >> edge;
	for (int i = 0; i < edge; i++) {
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	bfs(1);
}