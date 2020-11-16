#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
// # : Solid, .:Road
char map[1001][1001];
int visited[1001][1001];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int r, c;
queue<pair<int, int>> Fire;
pair<int, int> start;

int BFS() {
	queue<pair<int, int>> jj;
	int result = 0;
	jj.push(make_pair(start.first, start.second));
	visited[start.first][start.second] = 1;
	while (!jj.empty()) {
		int Fsize = Fire.size();
		for (int i = 0; i < Fsize; i++) {
			int x = Fire.front().first;
			int y = Fire.front().second;
			Fire.pop();
			for (int j = 0; j < 4; j++) {
				int n_x = x + dir[j][0];
				int n_y = y + dir[j][1];
				if ((0 <= n_x && n_x < r)&& (0 <= n_y && n_y < c)) {
					if (visited[n_x][n_y] ==0 &&map[n_x][n_y] =='.') {
						Fire.push(make_pair(n_x, n_y));
						map[n_x][n_y] = 'F';
						
					}
				}
			}
		}
		int Jsize = jj.size();
		for (int i = 0; i < Jsize; i++) {
			int x = jj.front().first;
			int y = jj.front().second;
			jj.pop();
			if (x==0||r-1 == x || c-1 == y||y==0) {
				return result+1;
			}
			for (int j = 0; j < 4; j++) {
					int n_x = x + dir[j][0];
					int n_y = y + dir[j][1];	
					if (visited[n_x][n_y] == 0 && map[n_x][n_y] != '#' && map[n_x][n_y] != 'F') {
						jj.push(make_pair(n_x, n_y));
						visited[n_x][n_y] = visited[x][y] + 1;
					}
					
			}
		}
		result++;
	}
	return -1;
}
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
int main() {
	init();
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin>>map[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'J') {
				start = make_pair(i, j);
			}
			else if (map[i][j] == 'F') {
				Fire.push(make_pair(i, j));
			}
	
		}
	}
	int temp = BFS();
	if (temp == -1) {
		cout << "IMPOSSIBLE";
	}
	else {
		cout << temp;
	}
}
