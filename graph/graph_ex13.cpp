#include <iostream>
#include <queue>

#define MAX 100

struct Ground{
    int x;
    int y;
    Ground(int x, int y){
        this->x=x;
        this->y=y;
    }
};

int map[MAX][MAX];
int group[MAX][MAX];
int dist[MAX][MAX];
int D[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
int N;

//1. 섬끼리 그릅을 지어준다.
void grouping(){
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(map[i][j]==1 && group[i][j]==0){
                group[i][j]=++cnt;
                std::queue<Ground> q;
                q.push(Ground(i,j));
                while(!q.empty()){
                    Ground g=q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx=g.x+D[k][0];
                        int ny=g.y+D[k][1];

                        if(nx<0 || ny <0 || nx>N-1 || ny>N-1) continue;

                        if(map[nx][ny]==1 && group[nx][ny]==0){
                            group[nx][ny]=cnt;
                            q.push(Ground(nx,ny));
                        }

                    }
                }
            }
        }
    }
}
//모든 육지부분을 queue에 넣어주고 다른 섬과의 거리를 bfs로 구해준다.
void distancing(){
    std::queue<Ground> q;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            //육지인 경우 0
            //육지가 아닌경우 -1
            dist[i][j]=-1;
            if(map[i][j]==1){
                dist[i][j]=0;
                q.push(Ground(i,j));
            }
        }
    }
    while(!q.empty()){
        Ground g=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=g.x+D[i][0];
            int ny=g.y+D[i][1];
            if(nx<0 || ny<0 || nx>N-1 || ny>N-1) continue;
            if(dist[nx][ny]==-1){
                dist[nx][ny]=dist[g.x][g.y]+1;
                //기존의 뻗어나간 육지번호를 안에 넣어줌.
                //후에 다른 섬과 맞닿는 부분을 찾기 위해 거리를 센 기준 그룹의 라벨링?
                group[nx][ny]=group[g.x][g.y];
                q.push(Ground(nx,ny));
            }
        }
    }
}
//서로 떨어져있는 거리가 저장되어있는 2차원 배열을 탐색하여
//다른 섬과의 최단거리를 구한다 (최단거리 = 가장 짧은 다리 길이) 출력
void bridge(){
    int ans=-1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<4;k++){
                int x=i+D[k][0];
                int y=j+D[k][1];
                if(x<0 || y<0 || x>N-1 || y>N-1) continue;
                //탐색하다 다른 그룹과 마주하게 된다면 다리가 다른 섬과 맞닿아있는 부분
                if(group[i][j]!=group[x][y]){
                    if(ans==-1 || ans> dist[i][j]+dist[x][y]){
                        ans=dist[i][j]+dist[x][y];
                    }
                }
            }
        }
    }
    std::cout<<ans<<'\n';
}

int main(){
    //(2146)
    // 다리만들기
    /*
        여러 섬으로 이루어진 나라가 있다. 
        이 나라의 대통령은 섬을 잇는 다리를 만들겠다는 공약으로 인기몰이를 해 당선될 수 있었다. 
        하지만 막상 대통령에 취임하자, 다리를 놓는다는 것이 아깝다는 생각을 하게 되었다. 
        그래서 그는, 생색내는 식으로 한 섬과 다른 섬을 잇는 다리 하나만을 만들기로 하였고, 
        그 또한 다리를 가장 짧게 하여 돈을 아끼려 하였다.

        이 나라는 N×N크기의 이차원 평면상에 존재한다. 
        이 나라는 여러 섬으로 이루어져 있으며, 섬이란 동서남북으로 육지가 붙어있는 덩어리를 말한다. 
        
        지도의 크기 N :: 100이하의 자연수
        입력의 0 :: 바다,  입력의 1 :: 육지
        항상 두 개 이상의 섬이 있는 데이터만 입력으로 주어진다.
    */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            std::cin>>map[i][j];
        }
    }
    grouping();
    distancing();
    bridge();
    return 0;
}