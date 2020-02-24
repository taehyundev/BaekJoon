#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int picture[500][500];
int visitBFS[500][500] = {0,};
int dir[4][2] = { {1,0}, {-1,0}, {0,1},{0,-1} };
int d_x, d_y;
int cnt = 0;
int sizeL[250000];
int k=0;
bool check(int x, int y) {
	return (0 <= x && x < d_x) && (0 <= y && y < d_y);
}

int BFS(int x, int y) {
	queue<pair<int, int>> move;
	move.push(make_pair(x, y));
	visitBFS[move.front().first][move.front().second] = 1;
	cnt++;
	while (!move.empty()) {
		x = move.front().first;
		y = move.front().second;
		move.pop();
		for (int i = 0; i < 4; i++) {
			int Next_x = x + dir[i][0];
			int Next_y = y + dir[i][1];
			if (check(Next_x,Next_y) && picture[Next_x][Next_y]==1 && visitBFS[Next_x][Next_y] ==0) {
				visitBFS[Next_x][Next_y] = 1;
				move.push(make_pair(Next_x, Next_y));
				visitBFS[Next_x][Next_y] = 1;
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	cin >> d_x >> d_y;
	for (int i = 0; i < d_x; i++) {
		for (int j = 0; j < d_y; j++) {
			cin >> picture[i][j];
		}
	}
	for (int i = 0; i < d_x; i++) {
		for (int j = 0; j < d_y; j++) {
			if (visitBFS[i][j] == 0 && picture[i][j] == 1) {
				sizeL[k] = BFS(i,j);
				k++;
				cnt = 0;
			}
		}
	}

	cout << k <<endl;
	sort(sizeL, sizeL+k);
	cout << sizeL[k-1];
}