#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>

#define MAX 100

int N,M;
int board[MAX][MAX];
int A[MAX][MAX];
int D[4][2]{{1,0},{-1,0},{0,1},{0,-1}};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // (1261)
    // 알고스팟
    // 알고스팟 운영진이 모두 미로에 갇혔다. 미로는 N*M 크기이며, 
    // 총 1*1크기의 방으로 이루어져 있다. 미로는 빈 방 또는 벽으로 이루어져 있고, 
    // 빈 방은 자유롭게 다닐 수 있지만, 벽은 부수지 않으면 이동할 수 없다.

    // 알고스팟 운영진은 여러명이지만, 항상 모두 같은 방에 있어야 한다. 
    // 즉, 여러 명이 다른 방에 있을 수는 없다. 어떤 방에서 이동할 수 있는 방은 상하좌우로 인접한 빈 방이다. 
    // 즉, 현재 운영진이 (x, y)에 있을 때, 
    // 이동할 수 있는 방은 (x+1, y), (x, y+1), (x-1, y), (x, y-1) 이다. 
    // 단, 미로의 밖으로 이동 할 수는 없다.

    // 벽은 평소에는 이동할 수 없지만, 
    // 알고스팟의 무기 AOJ를 이용해 벽을 부수어 버릴 수 있다. 
    // 벽을 부수면, 빈 방과 동일한 방으로 변한다.

    // 현재 (1, 1)에 있는 알고스팟 운영진이 (N, M)으로 이동하려면 
    // 벽을 최소 몇 개 부수어야 하는지 구하는 프로그램을 작성하시오.
    
    //가로크기 :: N 세로크기 :: M(1<=N,M<=100)
    
    std::cin>>M>>N;
    for(int i=0;i<N;i++){
        std::string tmp;
        std::cin>>tmp;
        for(int j=0;j<M;j++){
            board[i][j]=tmp[j]-'0';
        }
    }
    memset(A,-1,sizeof(A));
    //queue 2개를 이용한 문제 풀이
    std::queue<std::pair<int,int>> q1;
    std::queue<std::pair<int,int>> q2;

    q1.push(std::make_pair(0,0));
    A[0][0]=0;

    while(!q1.empty()){
        int x,y;
        std::tie(x,y)=q1.front();
        q1.pop();
        for(int i=0;i<4;i++){
            int nx=x+D[i][0];
            int ny=y+D[i][1];
            if(nx<0 || ny<0 || nx>N-1 || ny>M-1) continue;
            if(A[nx][ny]!=-1) continue;

            if(board[nx][ny]==0){//방이 뚫려 있는 경우
                // 최소 깨야하는 벽 수이므로 
                // 벽이 없는 경우가 우선순위가 더 높다고 할 수 있다.
                // 지금 탐색하는 q1에 push
                q1.push(std::make_pair(nx,ny));
                A[nx][ny]=A[x][y];
            }else{//방이 벽으로 막혀있는 경우
                // 깨야하는 벽이 늘어나므로
                // 후순위로 밀려나 q2에 push한다.
                q2.push(std::make_pair(nx,ny));
                A[nx][ny]=A[x][y]+1;
            }
        }
        if(q1.empty()){
            q1=q2;
            q2=std::queue<std::pair<int,int>>();
        }
    }
    std::cout<<A[N-1][M-1]<<'\n';
    return 0;
}