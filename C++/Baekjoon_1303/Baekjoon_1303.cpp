#include <iostream>
#include <queue>
using namespace std;
int map[100][101] = { 0, };
int visit[101][101] = { 0, };
int dir[4][2] = { {1,0},{-1,0}, {0,1},{0,-1} };
int m_x, m_y;
int cnt = 0;
bool man = false; // true면 아군
int O_team = 0; //우리팀 총계
int E_team = 0; //적팀 총계
bool check(int x, int y) {
	return (0 <= x && x < m_x) && (0 <= y && y < m_y);
}
int BFS(int cur_x, int cur_y) {
	cnt = 0;
	cnt++;
	queue<pair<int, int>> s;
	s.push(make_pair(cur_x, cur_y));
	visit[cur_x][cur_y] = 1;
	while (!s.empty()) {
		int qsize = s.size();
		while (qsize--) {
			cur_x = s.front().first;
			cur_y = s.front().second;
			s.pop();
			for (int i = 0; i < 4; i++) {
				int next_x = cur_x + dir[i][0];
				int next_y = cur_y + dir[i][1];
				if (man == true) {
					if (check(next_x, next_y) && visit[next_x][next_y] == 0 && map[next_x][next_y] == 1) {
						s.push(make_pair(next_x, next_y));
						visit[next_x][next_y] = 1;
						cnt++;
					}
				}
				else {
					if (check(next_x, next_y) && visit[next_x][next_y] == 0 && map[next_x][next_y] == 2) {
						s.push(make_pair(next_x, next_y));
						visit[next_x][next_y] = 1;
						cnt++;
					}
				}
			}
		}
	}
	return cnt;
}

int main() {
	// 아군 : 1 적군 : 2
	int tmp;
	cin >> m_y >> m_x;
	for (int i = 0; i < m_x; i++) {
		for (int j = 0; j < m_y; j++) {
			char c;
			cin >> c;
			if (c == 'W') {//울팀
				map[i][j] = 1;
			}
			else if (c == 'B') {//적팀
				map[i][j] = 2;
			}
		}
	}
	for (int i = 0; i < m_x; i++) {
		for (int j = 0; j < m_y; j++) {
			if (visit[i][j] == 0 && map[i][j] == 1) {
				man = true;
				tmp = BFS(i, j);
				O_team = O_team + (tmp * tmp);

			}
			else if (visit[i][j] == 0 && map[i][j] == 2) {
				man = false;
				tmp = BFS(i, j);
				E_team = E_team + (tmp * tmp);
			}
		}
	}
	cout << O_team << " " << E_team << endl;
}