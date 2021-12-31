#include <iostream>
#include <queue>
#include <algorithm>

struct Tomato{
    int x;
    int y;
    int day;//해당 토마토가 익은데 걸린 일 수
    Tomato(int x,int y,int day){
        this->x=x;
        this->y=y;
        this->day=day;
    }
};

int board[1000][1000]; // 토마토 상자표시
int N,M;
int D[4][2]{{1,0},{-1,0},{0,1},{0,-1}};

int bfs(){
    std::queue<Tomato> q;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(board[i][j]==1){
                //최초 토마토의 위치를 넣어준다.
                //처음에 익어있는 토마토는 0일로 침.
                q.push(Tomato(i,j,0)); 
            }
        }
    }
    int day=0;
    while(!q.empty()){
        Tomato t = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            //상하좌우 익지 않은 토마토를 익히기 위해 탐색
            int nx=t.x+D[i][0];
            int ny=t.y+D[i][1];

            //범위를 벗어나는경우와 토마토가 없거나 이미 익어있는 경우 건너뛰기
            if(nx<0 || ny<0) continue;
            if( nx>N-1 || ny>M-1 ) continue;
            if(board[nx][ny]==-1 || board[nx][ny]==1) continue;

            //조건을 통과한 곳에 토마토가 익었다고 표시해줌
            board[nx][ny]=1;
            //새로 익은 토마토에 대한 정보를 새로 queue에 push
            q.push(Tomato(nx,ny,t.day+1));
            day=t.day+1;
        }
    }
    // bfs 탐색 종료 후 익지 않은 토마토가 있는지 확인
    bool ok=true;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(board[i][j]==0){
                ok=false;
                break;
            }
        }
    }
    //익지 않은 토마토가 있다면 -1 반환
    //토마토가 전부 익었다면 모든 토마토가 익기까지 걸린 일 수 반환
    return ok ? day : -1;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    //(7576)
    // 토마토
    // 토마토 농장에 토마토를 보관하는 큰 창고를 가지고 있다.
    // 토마토는 격자모양 상자의 칸에 하나씩 넣어서 창고에 보관한다.
    // 창고에 보관된 토마토들 중에는 잘 익은 것도 있지만, 
    // 아직 익지 않은 토마토들도 있을 수 있다.
    // 익은 토마토드르이 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의
    // 영향을 받아서 익게 된다.
    // 인접한 곳 :: 위 아래 왼쪽 오른쪽
    // 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며
    // 토마토가 혼자 저절로 익는 경우는 없다고 가정한다.
    // 창고에 보관된 토마토들이 며칠이 지나면 다 익게되는지
    // 그 최소일수를 알고싶어한다.
    // 상자의 크기 :: N,M
    // (2<=N,M<=1,000)
    // 정수 1 :: 익은토마토
    // 정수 0 :: 익지 않은 토마토
    // 정수 -1 :: 토마토가 들어있지 않은 칸
    // 만약 저장 될 때 부터 모든 토마토가 익어있는 상황이라면 0을 출력해야 하고
    // 토마토가 모두 익지 못하는 상황이면 -1을 출력해야 한다.
    
    std::cin>> M >>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            std::cin>>board[i][j];
        }
    }

    std::cout<<bfs()<<'\n';
    return 0;
}