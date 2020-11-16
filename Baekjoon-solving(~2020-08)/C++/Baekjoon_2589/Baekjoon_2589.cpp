#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int map[50][50];
bool visited[50][50] = { false, };
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int x, y;
int sum[50][50] = { 0, };
int max_n;
int irand = 0;
int key = 0;
pair<int, int> start[50], goal[50];
bool checked(int m, int n) {
	return (0 <= m && m < x) && (0 <= n && n < y);
}

void BFS(int cur_x, int cur_y) {
	queue<pair<int, int>> q;
	int next_x;
	int next_y;
	//cnt[key] ++;
	q.push(make_pair(cur_x, cur_y));
	visited[q.front().first][q.front().second] = true;
	while (!q.empty()) {
		cur_x = q.front().first;
		cur_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			next_x = cur_x + dir[i][0];
			next_y = cur_y + dir[i][1];
			if (checked(next_x, next_y) && visited[next_x][next_y] == false && map[next_x][next_y] == 1) {
				q.push(make_pair(next_x, next_y));
				visited[next_x][next_y] = true;
				sum[next_x][next_y] = sum[cur_x][cur_y] + 1;
				max_n = max(max_n,sum[next_x][next_y]);
				//cout << next_x << ", " << next_y << endl;
				//goal[key] = make_pair(next_x, next_y);;
				//cnt[key]++;
			}
		}
	}
	//return cnt[key];
}
int main() {
	char p;
	cin >> x >> y;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> p;
			if (p == 'W') {
				map[i][j] = 0;
			}
			else if (p == 'L') {
				map[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (map[i][j] == 1) {
				irand++;
				//start[key] = make_pair(i, j);
				BFS(i, j);
				memset(visited, false, sizeof(visited));
				memset(sum, 0, sizeof(sum));
				//key++;
				//cout << goal.first << ", " << goal.second;
			}
		}
	}
	cout << max_n;
}
