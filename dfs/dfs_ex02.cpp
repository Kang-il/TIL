#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N,M;
int map[8][8];
int tmp[8][8];
int D[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
int ans=0;

//바이러스 전파
void spread(int x, int y){
    for(int i=0;i<4;i++){
        int nx=x+D[i][0];
        int ny=y+D[i][1];
        if(nx<0 || ny<0 || nx>N-1 || ny>M-1) continue;
        if(tmp[nx][ny]==0){
            tmp[nx][ny]=2;
            spread(nx,ny);
        } 
    }
}
int dfs(){
    // 바이러스 전파 테스트 해보기 위해 map의 값을 tmp 배열에 복사
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            tmp[i][j]=map[i][j];
        }
    }
    //전파
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(tmp[i][j]==2){
                spread(i,j);
            }
        }
    }
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(tmp[i][j]==0){
                cnt++;
            }
        }
    }
    return cnt;
}
void wall(int cnt){
    //벽 3개 설치 후 dfs 하여 기존 안전공간의 갯수와 현재 안전공간의 갯수를 비교하여 큰 값을 ans에 넣어준다.
    if(cnt==3){
        ans=max(ans,dfs());
        return;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==0){
                map[i][j]=1;
                wall(cnt+1);
                map[i][j]=0;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // (14502)
    // 연구소 - dfs 풀이
    // 인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다. 
    // 다행히 바이러스는 아직 퍼지지 않았고, 바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.
    // 연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다. 
    // 연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다. 
    // 일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다. 
    // 새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.

    // 벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역이라고 한다.
    // 연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램을 작성하시오.

    // 첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)

    // 둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 
    // 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다. 
    // 2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.

    // 빈 칸의 개수는 3개 이상이다.
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]==0){
                map[i][j]=1;
                wall(1);
                map[i][j]=0;
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}