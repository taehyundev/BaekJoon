#include <iostream>
using namespace std;
int matrix[1001][1001] = {0};
int DFS_visit[1001] = {0};
int BFS_visit[1001] = {0};
int queue[1001];
int edge;

void DFS(int start_vertax) {
	cout << start_vertax <<" ";
	DFS_visit[start_vertax] = 1;
	for (int i = 1; i <= edge; i++) {
		if (matrix[start_vertax][i] == 1 && DFS_visit[i] == 0)
			DFS(i);
	}
}

void BFS_Child_Visit(int *rear,int v) {
	cout << v << " ";
	queue[(*rear)++] = v;
	BFS_visit[v] = 1;

}

void BFS(int start_vertax) {
	int front = 0, rear = 0;
	int data ,i;
	BFS_Child_Visit(&rear,start_vertax);
	while (front < rear) {//front <rear
		data = queue[front++];
		for (i = 1; i <= edge; i++) {
			if (matrix[data][i] == 1 && BFS_visit[i] == 0) {
				BFS_Child_Visit(&rear, i);
			}
		}
	}
}

int main() {
	int vertax,start_vertax;
	int i = 0;
	int x, y;
	cin >> edge >> vertax >> start_vertax;
	do{
		cin >> x >> y;
		matrix[x][y] = 1;
		matrix[y][x] = 1;
		i++;
	} while (i < vertax);
	DFS(start_vertax);
	cout << "\n";
	BFS(start_vertax);
}