#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#define MAX 1000
using namespace std;

int N,M,K;
int board[MAX][MAX];
bool visited[MAX][MAX][11];

int D[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
void bfs(){
    // row, col, 이동 거리, 벽을 부순 갯수, 낮/밤 (true/false);
    queue<pair<tuple<int,int,int>,pair<int,bool>>> q;
    q.push(make_pair(make_tuple(0,0,1),make_pair(0,true)));
    visited[0][0][0]=true;
    while(!q.empty()){
        auto cur=q.front();
        q.pop();
        int x,y,cnt;
        tie(x,y,cnt)=cur.first;
        int break_count=cur.second.first;
        bool day=cur.second.second;

        if(x==N-1 && y==M-1){
            cout<<cnt<<'\n';
            return;
        }
        for(int i=0;i<4;i++){
            int nx=x+D[i][0];
            int ny=y+D[i][1];
            if(nx<0 || ny<0 || nx>N-1 || ny>M-1) continue;
            // 벽이 아닌경우
            if(board[nx][ny]==0){
                if(visited[nx][ny][break_count]==false){
                    visited[nx][ny][break_count]=true;
                    // 벽이 아닌경우는 낮인지 밤인지 상관없이 이동가능함
                    // 이동위치/ count, 기존 낮/밤(true/false)을 반전시켜주기만 하면 된다.
                     q.push(make_pair(make_tuple(nx,ny,cnt+1),make_pair(break_count,!day)));
                }
            //벽인 경우
            }else if(board[nx][ny]==1){
                if(break_count<K){
                    if(visited[nx][ny][break_count+1]==false){
                        //벽인경우 낮/밤(true/false)가 중요하기 때문에 이를 기준으로 분기한다
                        if(day){//낮인 경우
                            visited[nx][ny][break_count+1]=true;
                            // 낮인경우 벽을 부술 수 있으므로 break_count를 +1해주고 day를 반전시겨줌
                            q.push(make_pair(make_tuple(nx,ny,cnt+1),make_pair(break_count+1,!day)));
                        }else{
                            // 밤인경우 이동이 불가하므로 원래의 x,y값에 count만 1 더해주고 day반전 시켜준다.
                            q.push(make_pair(make_tuple(x,y,cnt+1),make_pair(break_count,!day)));                            
                        }
                     }
                }
            }
        }
    }
    cout<<-1<<'\n';
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //(16933)
    // 벽 부수고 이동하기 3
    // N×M의 행렬로 표현되는 맵이 있다. 
    // 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 
    // 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 
    // 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다. 
    // 이동하지 않고 같은 칸에 머물러있는 경우도 가능하다. 
    // 이 경우도 방문한 칸의 개수가 하나 늘어나는 것으로 생각해야 한다.
    // 이번 문제에서는 낮과 밤이 번갈아가면서 등장한다. 
    // 가장 처음에 이동할 때는 낮이고, 한 번 이동할 때마다 낮과 밤이 바뀌게 된다. 
    // 이동하지 않고 같은 칸에 머무르는 경우에도 낮과 밤이 바뀌게 된다.
    // 만약에 이동하는 도중에 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 K개 까지 부수고 이동하여도 된다. 
    // 단, 벽은 낮에만 부술 수 있다.
    // 한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.
    // 맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.
    cin>>N>>M>>K;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        // 0 :: 빈 공간  1 :: 벽
        for(int j=0;j<M;j++){
            board[i][j]=str[j]-'0';
        }
    }
    bfs();
    return 0;
}