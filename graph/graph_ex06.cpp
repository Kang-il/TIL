#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

struct Point{
    int x;
    int y;
    Point(int x,int y){
        this->x=x;
        this->y=y;
    }
};

int W,H;

int board[100][100];
int A[100][100];
int D[8][2]{{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};

void bfs(int x, int y, int cnt){
    std::queue<Point> q;
    q.push(Point(x,y));
    A[x][y]=cnt;
    while(!q.empty()){
        Point p=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int nx=p.x+D[i][0];
            int ny=p.y+D[i][1];
            if(nx>=0 && nx < H && ny>=0 && ny < W){
                if(A[nx][ny]==0 && board[nx][ny]==1){
                    q.push(Point(nx,ny));
                    A[nx][ny]=cnt;
                }
            }
        }
    }
}
int main(){
    // (4963)
    // 섬의 개수
    // 정사각형으로 이루어져 있는 섬과 바다지도가 주어진다. 섬의 개수를 세는 프로그램을 작성하시오.
    // 한 정사각형과, 가로 세로 또는 대각선으로 연결되어있는 사각형은 걸어갈 수 있는 사각형이다.
    // 두 정사각형이 같은 섬에 있으려면, 
    // 한 정사각형에서 다른 정사각형으로 걸어갈 수 있는 경로가 있어야 한다.
    // 지도는 바다로 둘러싸여 있으며, 지도 밖으로 나갈 수 없다.
    // 지도의 너비 W와 높이 H가 주어진다 (1<=W,H<=50)
    // H개의 줄에 지도가 주어진다. 1은 땅 0은 바다이다.
    while(true){
        scanf("%d %d", &W,&H);
        if(!W && !H) {
            break;
        }
        
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                scanf("%1d",&board[i][j]);
            }
        }
        int cnt=0;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(board[i][j]==1 && A[i][j]==0){
                    bfs(i,j,++cnt);
                }
            }
        }
        memset(A,0,sizeof(A));
        printf("%d\n",cnt);
    }
    return 0;
}