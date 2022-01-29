#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;
struct POINT{
    int x,y,dist,break_count;
    POINT(int x, int y, int dist, int break_count):x(x),y(y),dist(dist),break_count(break_count){}
};
int N,M,K; 
int board[MAX][MAX];
bool visited[MAX][MAX][10];
int D[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
int ans=-1;
void bfs(){
    queue<POINT> q;
    q.push(POINT(0,0,1,0));
    visited[0][0][0]=true;
    while(!q.empty()){
        POINT p=q.front();
        q.pop();
        if(p.x==N-1 && p.y==M-1){
            cout<<p.dist<<'\n';
            return;
        }
        for(int i=0;i<4;i++){
            int nx=p.x+D[i][0];
            int ny=p.y+D[i][1];
            if(nx<0 || ny<0 || nx>N-1 || ny>M-1) continue;
            if(visited[nx][ny][p.break_count]==false){
                if(board[nx][ny]==0){
                    visited[nx][ny][p.break_count]=true;
                    q.push(POINT(nx,ny,p.dist+1,p.break_count));
                }else if(board[nx][ny]==1 && p.break_count<K){
                    visited[nx][ny][p.break_count+1]=true;
                    q.push(POINT(nx,ny,p.dist+1,p.break_count+1));
                }
            }
        }
    }
    cout<<-1<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // (14442)
    // 벽 부수고 이동하기 2
    // N×M의 행렬로 표현되는 맵이 있다. 
    // 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 
    // 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 
    // 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.
    // 만약에 이동하는 도중에 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 K개 까지 부수고 이동하여도 된다.
    // 한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.
    // 맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

    // 첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000), K(1 ≤ K ≤ 10)이 주어진다. 
    // 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.
    
    // 최단거리를 출력한다. 단, 불가능 할 때는 -1을 출력한다.
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        for(int j=0;j<M;j++){
            board[i][j]=str[j]-'0';
        }
    }
    bfs();
    return 0;
}