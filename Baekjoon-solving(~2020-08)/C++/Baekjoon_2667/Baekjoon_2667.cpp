#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;
int graph[25][25] = {0,};
int bfs_visit[25][25] = {0,};
int sizen[625] = {0,};
int key = 0;
int num;
int dir[4][2] = { {1,0},{-1,0},	{0,1},{0,-1}
};
int cnt =0;

bool isinput(int x, int y) {
	return (0 <= x && x < num) && (0 <= y && y < num);
}

int bfs(int x, int y) {
	int max = 0;
	queue<pair<int, int>> q;
	bfs_visit[x][y] == 1;
	max++;
	q.push(pair<int, int>(x, y));
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) { // 방향
			int next_X = x + dir[i][0];
			int next_Y = y + dir[i][1];
			if (isinput(next_X,next_Y) && graph[next_X][next_Y]!=0 && bfs_visit[next_X][next_Y] ==0) {
				bfs_visit[next_X][next_Y] = 1;
				q.push(pair<int, int>(next_X, next_Y));
				max++;
			}
		}
	}
	return max;
}

int main() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (bfs_visit[i][j] == 0 && graph[i][j] == 1) {
				cnt++;
				sizen[key] = (bfs(i, j));
				if (sizen[key] > 1) {
					sizen[key]--;
				}
				key++;
			}
		}
	}
	cout << cnt<<endl;
	sort(sizen,sizen+cnt);
	for (int i = 0; i < cnt; i++) {
		cout << sizen[i] << endl;
	}


	
}