#include <iostream>
#include <queue>
#include <algorithm>

struct Knight{
    int x;
    int y;
    int cnt; // 현 위치로 오기까지 나이트가 이동한 횟수를 저장.
    Knight(int x, int y,int cnt){
        this->x=x;
        this->y=y;
        this->cnt=cnt;
    }
};

int N; //체스판 크기
int DX,DY;//나이트가 이동하려는 위치
int board[300][300];//체스판

//나이트 이동 규칙
int D[8][2]{{-2,-1},{-2,1},{2,-1},{2,1},{-1,2},{1,2},{1,-2},{-1,-2}};

int bfs(int x,int y){
    std::queue<Knight> q;
    //최초 나이트위 위치 -- 이동한 적 없으므로 cnt==0
    q.push(Knight(x,y,0));
    while(!q.empty()){
        Knight k=q.front();
        q.pop();
        //만약 현 나이트의 위치가 이동하려는 나이트 위치와 동일하다면
        //현재 나이트의 cnt값을 반환한다.
        if(k.x==DX && k.y==DY){
            return k.cnt;
        }
        //나이트를 이동시켜본다.
        for(int i=0;i<8;i++){
            int nx=k.x+D[i][0];
            int ny=k.y+D[i][1];
            //체스판을 벗어나는 경우는 건너뛴다.
            if(nx<0 || ny<0) continue;
            if(nx>N || ny>N) continue;
            //board[nx][ny]==1 --> 이전에 나이트가 방문한 적 있는 위치
            //최소값을 구하는 문제이기 때문에 이미 이동한적 있는 땅은 건너뛴다.
            if(board[nx][ny]==1) continue;
            board[nx][ny]=1;
            q.push(Knight(nx,ny,k.cnt+1));
        }
    }
    return 0;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    //(7562)
    // 나이트의 이동
    // 체스판 위에 한 나이트가 놓여져 있다.
    // 나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다
    // 참고 :: https://www.acmicpc.net/problem/7562
    // 체스판 한 변의 길이 :: N (4<=N<=300)
    // 체스판 각 쌍은 두 수의 쌍 {0,...,N-1}*{0,...,N-1}로 나타낼 수 있다.
    // 나이트가 현재 있는 칸이 주어진 후 
    // 나이트가 이동하려는 칸이 주어진다.

    int T;
    std::cin>>T;
    while(T--){
        int X,Y;
        std::cin>>N;//체스판 크기
        std::cin>>X>>Y;//현재 나이트 위치
        std::cin>>DX>>DY;//나이트가 이동하려는 위치

        for(int i=0;i<N;i++){// 체스판 초기화
            for(int j=0;j<N;j++){
                board[i][j]=0;
            }
        }
        //나이트 현위치 표시
        board[X][Y]=1;
        std::cout<<bfs(X,Y)<<'\n';
    }
    return 0;
}