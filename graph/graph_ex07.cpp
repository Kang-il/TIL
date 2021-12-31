#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

struct Point{
    int x;
    int y;
    Point(int x, int y){
        this->x=x;
        this->y=y;
    }
};

int N,M;//보드 크기
int board[100][100];//보드
int A[100][100];//거리
bool visited[100][100];//방문여부
int D[4][2]{{1,0},{-1,0},{0,1},{0,-1}};

void bfs(int x,int y){
    std::queue<Point> q;
    visited[x][y]=true;
    A[x][y]=1;
    q.push(Point(x,y));

    while(!q.empty()){
        Point p=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=p.x+D[i][0];
            int ny=p.y+D[i][1];

            if(nx<0 || ny<0) continue;
            if(nx>N || ny>M) continue;
            if(visited[nx][ny] || board[nx][ny]==0) continue;

            q.push(Point(nx,ny));
            A[nx][ny]=A[p.x][p.y]+1;
            visited[nx][ny]=true;
        }
    }
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //(2178)
    // 미로 탐색
    // N*M 크기의 배열로 표현되는 미로가 있다.
    // 미로에서 1은 이동할 수 있는 칸을 나타내고 0은 이동할 수 없는 칸을 나타낸다.
    // 이러한 미로가 주어졌을 때, (1,1) 에서 출발하여 (N,M)의 위치로
    // 이동할 때 서로 인접한 칸으로만 이동할 수 있다.
    // 지나야 하는 최소 칸의 수를 출력한다.
    // 항상 도착위치로 이동할 수 있는 경우에만 입력으로 주어진다.
    // ( 2 <= N,M <= 100)
    // 지나야 하는 최소의 칸 수를 출력한다.
    std::cin>>N>>M;

    for(int i=0;i<N;i++){
        std::string tmp;
        std::cin>>tmp;
        for(int j=0;j<M;j++){
            board[i][j]=tmp[j]-'0';
        }
    }

    bfs(0,0);
    std::cout<<A[N-1][M-1]<<'\n';
    return 0;
}