#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
 
struct Point {
    int y, x;
};
 
int n;
char inputMap[55][55];
int height[55][55];
int starty, startx;
int visit[55][55];
int sz;
int range[2600];
Point point[2600];
int ans = 1e9;
 
int dijkstra(int num) {
 
    int map[55][55];
    int state[55][55];
 
    int dy[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
    int dx[8] = { 0, -1, 1, 0, -1, 1, -1, 1 };
 
    if (height[starty][startx] < num)    return 0;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visit[i][j] = 1e9;
            map[i][j] = state[i][j] = 0;
            if (height[i][j] >= num)        map[i][j] = 1;
        }
    }
 
    priority_queue<pair<int, pair<int, int> > > que;
    visit[starty][startx] = height[starty][startx];
    que.push(make_pair(height[starty][startx] * -1, make_pair(starty, startx)));
 
    while (!que.empty()) {
        int y = que.top().second.first;
        int x = que.top().second.second;
        int h = que.top().first * -1;
        que.pop();
 
        if (h <= visit[y][x]) {
            for (int i = 0; i < 8; i++) {
                int nexty = y + dy[i];
                int nextx = x + dx[i];
 
                int newh = (h > height[nexty][nextx]) ? h : height[nexty][nextx];
 
                if (nexty >= 0 && nexty < n && nextx >= 0 && nextx < n) {
                    if (map[nexty][nextx] == 1 && newh < visit[nexty][nextx]) {
                        visit[nexty][nextx] = newh;
                        que.push(make_pair(newh * -1, make_pair(nexty, nextx)));
                    }
                }
            }
        }
    }
 
    int mx = 0;
    for (int i = 0; i < sz; i++) {
        if (visit[point[i].y][point[i].x] > mx)    mx = visit[point[i].y][point[i].x];
        if (visit[point[i].y][point[i].x] == 0)    return 0;
    }
 
    if (mx - num < ans)    ans = mx - num;
 
    return 1;
}
 
void solve()
{
    int mn = 1e9, mx = 0;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (inputMap[i][j] == 'P') {
                starty = i;
                startx = j;
            }
            else if (inputMap[i][j] == 'K') {
                point[sz].y = i;
                point[sz].x = j;
                sz++;
            }
 
            if (height[i][j] < mn)    mn = height[i][j];
            if (height[i][j] > mx)    mx = height[i][j];
        }
    }
 
    sort(range, range + n * n);
 
    int cnt = 1;
    for (int i = 1; i < n * n; i++) {
        if (range[i - 1] != range[i])        range[cnt++] = range[i];
    }
 
    int s = 0, e = cnt - 1;
    int m;
 
    while (s <= e) {
        m = (s + e) / 2;
 
        if (dijkstra(range[m]))    s = m + 1;
        else                       e = m - 1;
    }
 
    for (int i = 0; i <= e; i++) {
        dijkstra(range[i]);
    }
    printf("%d", ans);
}
 
int main()
{
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++) {
        scanf("%s", inputMap[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &height[i][j]);
            range[i * n + j] = height[i][j];
        }
    }
 
    solve();
 
    return 0;
}