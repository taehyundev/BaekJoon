#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

const int MAX = 10000;
int start, goal;
bool visited[MAX];

string BFS() {

	queue<pair<int, string>> q;
	q.push(make_pair(start, ""));
	visited[start] = true;
	
	while (!q.empty()) {
		int num = q.front().first;
		string control = q.front().second;
		q.pop();
		if (num == goal) {
			return control;
		}

		//D
		int cache = (num * 2) % MAX;
		if (!visited[cache]) {
			visited[cache] = true;
			q.push(make_pair(cache, control+"D"));
		}
		//S
		cache = (num - 1) < 0 ? 9999 : num-1;
		if (!visited[cache]) {
			visited[cache] = true;
			q.push(make_pair(cache, control+"S"));
		}
		//L
		cache = (num / 1000) +((num % 1000)*10);
		if (!visited[cache]) {
			visited[cache] = true;
			q.push(make_pair(cache, control+"L"));
		}
		//R
		cache = ((num % 10) * 1000) + (num / 10);
		if (!visited[cache]) {
			visited[cache] = true;
			q.push(make_pair(cache, control+"R"));
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		memset(visited, false, sizeof(visited));
		cin >> start >> goal;
		cout<<BFS()<<endl;
	}
	return 0;
}
