#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define INF 2147483647
#define MAX 100
using namespace std;
struct LAZER{
    int x,y,cnt;
    int prevIdx;
    LAZER(int x, int y, int cnt,int prevIdx):x(x),y(y),cnt(cnt),prevIdx(prevIdx){} 
};
int H,W;
char board[MAX][MAX];
int visited[MAX][MAX];
vector<pair<int,int>> connect;
int D[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
void solution(){
    queue<LAZER> q;
    for(int i=0;i<4;i++){
        //나아가는 방향 설정 -- 초기엔 모든 방향으로 뻗어갈 수 있음.
        q.push(LAZER(connect[0].first,connect[0].second,0,i));
    }
    visited[connect[0].first][connect[0].second]=0;
    while(!q.empty()){
        LAZER cur=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=cur.x+D[i][0];
            int ny=cur.y+D[i][1];
            int nCnt = cur.cnt;
            if(nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            if(board[nx][ny]=='*') continue;
            //이전 나아간 방향과 다르다면 꺾은 것
            if(cur.prevIdx != i) nCnt+=1;
            if(visited[nx][ny]>=nCnt){
                visited[nx][ny]=nCnt;
                q.push(LAZER(nx,ny,nCnt,i));
            }
        }
    }
    cout<<visited[connect[1].first][connect[1].second]<<'\n';
    return;
}
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>W>>H;
    for(int i=0;i<H;i++){
        string str;
        cin>>str;
        for(int j=0;j<W;j++){
            board[i][j]=str[j];
            if(board[i][j]=='C'){
                connect.push_back(make_pair(i,j));
            }
            visited[i][j]=INF;
        }
    }
}
int main(){
    //(6087)
    // 레이저 통신
    // 크기가 1×1인 정사각형으로 나누어진 W×H 크기의 지도가 있다. 
    // 지도의 각 칸은 빈 칸이거나 벽이며, 두 칸은 'C'로 표시되어 있는 칸이다.
    // 'C'로 표시되어 있는 두 칸을 레이저로 통신하기 위해서 설치해야 하는 거울 개수의 최솟값을 구하는 프로그램을 작성하시오. 
    // 레이저로 통신한다는 것은 두 칸을 레이저로 연결할 수 있음을 의미한다.
    // 레이저는 C에서만 발사할 수 있고, 빈 칸에 거울('/', '\')을 설치해서 방향을 90도 회전시킬 수 있다. 
    
    // 첫째 줄에 W와 H가 주어진다. (1 ≤ W, H ≤ 100)
    // 둘째 줄부터 H개의 줄에 지도가 주어진다. 지도의 각 문자가 의미하는 것은 다음과 같다.

    // .: 빈 칸
    // *: 벽
    // C: 레이저로 연결해야 하는 칸

    // 'C'는 항상 두 개이고, 레이저로 연결할 수 있는 입력만 주어진다.
    input();
    solution();
    return 0;
}
