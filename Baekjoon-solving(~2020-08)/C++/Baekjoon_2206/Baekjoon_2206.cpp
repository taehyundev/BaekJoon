#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

bool visit[2][1001][1001] = { false, }; // visit[0]~ : 벽 안 부숨, visit[1]~ : 벽 부숨

int map[1001][1001] = { 0, };

int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

int N = 0, M = 0;

queue<pair<int, pair<int, int> > > q;

int BFS()
{
    q.push({ 0, {1, 1} }); // 문제 조건에 의해 (1, 1)에서 출발하고, 벽은 당연히 안 부순 상태(0)

    visit[0][1][1] = true; // 벽 안 부순 상태 + (1, 1) 방문 표시

    int ret = 1; // 시작하는 칸도 포함해야 하기 때문에 1부터 시작.(문제 조건)

    while (!q.empty())
    {
        int qSize = q.size();

        while (qSize--)
        {
            int current = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;

            q.pop();

            if (r == N && c == M)
            {
                return ret;
            }

            for (int i = 0; i < 4; i++)
            {
                int y = r + dy[i];
                int x = c + dx[i];
                if (y <= 0 || y > N || x <= 0 || x > M || visit[current][y][x]) continue;
                if (current == 0) 
                {
                    if (map[y][x] == 1) 
                    {
                        q.push({ 1, {y, x} }); 
                        visit[1][y][x] = true;
                    }
                    else if (map[y][x] == 0)
                    {
                        q.push({ 0, { y, x } });
                        visit[0][y][x] = true;
                    }
                }
                else if (current == 1) 
                {
                    if (map[y][x] == 0) 
                    {
                        q.push({ 1, { y, x } });
                        visit[1][y][x] = true;
                    }
                }
            }
        }

        ++ret;
    }

    return -1;
}

int main(void)
{
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    printf("%d\n", BFS());

    return 0;
}
