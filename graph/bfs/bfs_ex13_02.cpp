#include <iostream>
#include <queue>
#include <vector>
#define MAX 1000
using namespace std;
struct POINT{
    int x,y;
    POINT(int x, int y):x(x),y(y){}
};
int N,M;
int board[MAX][MAX];
bool visited[MAX][MAX];
int D[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
void bfs(int x, int y){
    queue<POINT> q;
    vector<POINT> wall;
    q.push(POINT(x,y));
    visited[x][y]=true;
    int cnt=1;
    while(!q.empty()){
        POINT p=q.front();
        q.pop();
        for(int i=0;i<4;i++){      
            int nx=p.x+D[i][0];
            int ny=p.y+D[i][1];
            if(nx<0 || ny<0 || nx>N-1 || ny>M-1) continue;
            if(board[nx][ny]==0 && visited[nx][ny]==false){
                visited[nx][ny]=true;
                q.push(POINT(nx,ny));
                cnt++;
            }else if(board[nx][ny]!=0 && visited[nx][ny]==false){
                visited[nx][ny]=true;
                wall.push_back(POINT(nx,ny));
            }
        }
    }
    //탐색하면서 만난 벽돌에 갯수를 더해줌.
    for(int i=0;i<wall.size();i++){
         board[wall[i].x][wall[i].y]+=cnt;
         visited[wall[i].x][wall[i].y]=false;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // (16946)
    // 벽 부수고 이동하기 4
    // N×M의 행렬로 표현되는 맵이 있다. 
    // 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 
    // 한 칸에서 다른 칸으로 이동하려면, 두 칸이 인접해야 한다. 두 칸이 변을 공유할 때, 인접하다고 한다.

    // 각각의 벽에 대해서 다음을 구해보려고 한다.

    // 벽을 부수고 이동할 수 있는 곳으로 변경한다.
    // 그 위치에서 이동할 수 있는 칸의 개수를 세어본다.
    // 한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        for(int j=0;j<M;j++){
            board[i][j]=str[j]-'0';
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            //방문하지 않는 0마다 bfs를 호출한다. -> 탐색하면서 만난 벽들에 그 개수를 더해주도록한다.
            if(board[i][j]==0 && visited[i][j]==false){
                bfs(i,j);
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<board[i][j]%10;
        }
        cout<<'\n';
    }
    return 0;
}