#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define MAX 50
using namespace std;
struct POINT{
    int x,y;
    int cnt;
    POINT(int x,int y,int cnt):x(x),y(y),cnt(cnt){}
};
int N,M;
char board[MAX][MAX];
bool visited[MAX][MAX];
int water[MAX][MAX];
int D[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
queue<pair<int,int>> water_q;
//waterMap 마킹
void make_water_map(){
    while(!water_q.empty()){
        int qSize=water_q.size();
        for(int i=0;i<qSize;i++){
            int x=water_q.front().first;
            int y=water_q.front().second;
            water_q.pop();
            for(int i=0;i<4;i++){
                int nx=x+D[i][0];
                int ny=y+D[i][1];
                if(nx<0 || ny<0 || nx>N-1 || ny>M-1) continue;
                if(board[nx][ny]=='.'){
                    // 이미 물이 차있게 마킹이 되어있다
                    // 근데 이미 마킹되어있는 숫자보다 작은 수가 들어온다?
                    // 바꿔줌
                    // 물이 여러 영역으로 나누어져있을 경우
                    // 물이 차오르다 서로 만날 수 있다.
                    // 서로 만났을 경우 더 적은 시간동안 차오른 물이 우선되어야 정확하게 water map 마킹 가능
                    if(water[nx][ny]>water[x][y]+1){
                        water[nx][ny]=water[x][y]+1;
                        water_q.push(make_pair(nx,ny));
                    }
                }
            }
        }
    }
}
void bfs(int dx, int dy, int sx, int sy){
    queue<POINT>q;
    q.push(POINT(sx,sy,0));
    visited[sx][sy]=true;

    while(!q.empty()){
        POINT cur= q.front();
        q.pop();
        //bfs 탐색중 비버굴 도착시 이동 횟수 출력 후 return
        if(cur.x==dx && cur.y==dy){
            cout<<cur.cnt<<'\n';
            return;
        }
        for(int i=0;i<4;i++){
            int nx=cur.x+D[i][0];
            int ny=cur.y+D[i][1];
            //보드범위
            if(nx<0 || ny<0 || nx>N-1 || ny>M-1) continue;
            // 최솟값 -- 같은곳 재방문x
            if(visited[nx][ny]) continue;
            //바위
            if(board[nx][ny] =='X') continue;
            //이동 횟수가 물이 찰 예정순서보다 큰 경우 못가는 영역
            if(water[nx][ny] <= cur.cnt+1) continue;

            visited[nx][ny]=true;
            q.push(POINT(nx,ny,cur.cnt+1));
        }
    }
    //bfs 탐색 후에도 답을 발견 못한경우 출력
    cout<<"KAKTUS"<<'\n';
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // (3055)
    // 탈출
    // 사악한 암흑의 군주 이민혁은 드디어 마법 구슬을 손에 넣었고, 
    // 그 능력을 실험해보기 위해 근처의 티떱숲에 홍수를 일으키려고 한다. 
    // 이 숲에는 고슴도치가 한 마리 살고 있다. 고슴도치는 제일 친한 친구인 비버의 굴로 가능한 빨리 도망가 홍수를 피하려고 한다.

    // 티떱숲의 지도는 R행 C열로 이루어져 있다. 
    // 비어있는 곳은 '.'로 표시되어 있고, 물이 차있는 지역은 '*', 돌은 'X'로 표시되어 있다. 
    // 비버의 굴은 'D'로, 고슴도치의 위치는 'S'로 나타내어져 있다.

    // 매 분마다 고슴도치는 현재 있는 칸과 인접한 네 칸 중 하나로 이동할 수 있다. 
    // (위, 아래, 오른쪽, 왼쪽) 물도 매 분마다 비어있는 칸으로 확장한다. 
    // 물이 있는 칸과 인접해있는 비어있는 칸(적어도 한 변을 공유)은 물이 차게 된다. 
    // 물과 고슴도치는 돌을 통과할 수 없다. 또, 고슴도치는 물로 차있는 구역으로 이동할 수 없고, 물도 비버의 소굴로 이동할 수 없다.

    // 티떱숲의 지도가 주어졌을 때, 고슴도치가 안전하게 비버의 굴로 이동하기 위해 필요한 최소 시간을 구하는 프로그램을 작성하시오.

    // 고슴도치는 물이 찰 예정인 칸으로 이동할 수 없다. 
    // 즉, 다음 시간에 물이 찰 예정인 칸으로 고슴도치는 이동할 수 없다. 
    // 이동할 수 있으면 고슴도치가 물에 빠지기 때문이다. 

    // 풀이 포인트 -- 고슴도치는 물이 찰 예정인 칸으로 이동할 수 없다
    // water 2차원 배열 맵을 통해 물이 차는 순서를 마킹 해준다.
    // bfs를 통해 고슴도치 이동경로를 탐색 할 때 사용
    // 고슴도치 이동 수 (cnt)+1 보다 water맵에 마킹되어있는 수보다 같거나 클 경우 이동할 수 없는 경로다.
    // 고슴도치가 이동 한 곳에 물이 찰 예정이거나 물이 이미 차 있는 곳이므로
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            //water 맵 999로 초기화
            water[i][j]=999;
        }
    }
    int dx,dy,sx,sy;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        for(int j=0;j<M;j++){
            board[i][j]=str[j];
            if(board[i][j]=='D'){
                dx=i;
                dy=j;
            }else if(board[i][j]=='S'){
                sx=i;
                sy=j;
            }else if(board[i][j]=='*'){
                water[i][j]=0;
                water_q.push(make_pair(i,j));
            }
        }
    }
    make_water_map();
    bfs(dx,dy,sx,sy);
    return 0;
}
