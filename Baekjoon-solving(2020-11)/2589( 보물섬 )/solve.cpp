#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;
char map[51][51];
int visit[51][51];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int y,x;
bool check(int cx,int cy){
    return (0<=cx && cx<x) && (0<=cy && cy < y);
}
int BFS(int cur_x, int cur_y){
	memset(visit, -1, sizeof(visit));
    int cnt =0;
    queue<pair<int, int>>q;
    q.push({cur_x,cur_y});
    visit[cur_x][cur_y] = 0;
    while(!q.empty()){
        int qSize = q.size();
        for(int i=0; i< qSize; i++){
            cur_x = q.front().first;
            cur_y = q.front().second;
            q.pop();
            cnt = max(cnt, visit[cur_x][cur_y]);
            for(int j=0; j<4; j++){
                int nx = cur_x + dir[j][0];
                int ny = cur_y + dir[j][1];
                if(check(nx,ny)&&map[nx][ny]=='L' && visit[nx][ny] ==-1){
                    visit[nx][ny]=visit[cur_x][cur_y] +1;
                    q.push({nx,ny});

                }
            }
        }
    }
    return cnt;
}
int main(){

    cin >> x>>y;
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            cin >> map[i][j];
        }
    }
    
	int result = 0;
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            if(map[i][j] =='L'){
                result = max(BFS(i,j),result);
            }
        }
    }
    cout <<result<<endl;

}