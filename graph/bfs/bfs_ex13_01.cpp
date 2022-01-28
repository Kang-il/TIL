#include <iostream>
#include <queue>
#include <cstring>
#define MAX 1000
using namespace std;
/*


시간초과가 나는 방식
-- 이유 :: visited 배열을 매번 false 로 초기화 하고
 여러번 bfs를 새로 시도하는 과정때문에 시간초과가 난다.


*/
struct POINT{
    int x,y;
    POINT(int x, int y):x(x),y(y){}
};
int N,M;
char board[MAX][MAX];
int res[MAX][MAX];
bool visited[MAX][MAX];
int D[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
void bfs(int x, int y){
    queue<POINT> q;
    q.push(POINT(x,y));
    visited[x][y]=true;
    res[x][y]=1;
    while(!q.empty()){
        POINT p=q.front();
        q.pop();
        for(int i=0;i<4;i++){      
            int nx=p.x+D[i][0];
            int ny=p.y+D[i][1];
            if(nx<0 || ny<0 || nx>N-1 || ny>M-1) continue;
            if(visited[nx][ny]) continue;
            if(board[nx][ny]=='1') continue;
            visited[nx][ny]=true;
            q.push(POINT(nx,ny));
            res[x][y]++;
        }
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
            board[i][j]=str[j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(board[i][j]=='0'){
                res[i][j]=0;
            }else if(board[i][j]=='1'){
                // visited 를 초기화하고 계속 처음부터 bfs를 
                // 시도해서 시간 초과가 났다.
                memset(visited,false,sizeof(visited));
                bfs(i,j);
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<res[i][j]%10;
        }
        cout<<'\n';
    }
    return 0;
}