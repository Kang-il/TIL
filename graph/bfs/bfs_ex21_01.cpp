#include <iostream>
#include <queue>
#include <string>
#define MAX 100
using namespace std;
struct POINT{
    int x,y;
    POINT(int x, int y):x(x),y(y){}
};
int N;
char board[MAX][MAX];
bool visited[MAX][MAX][2];
int D[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
// first :: 색약이 아닐경우
// second :: 색약일 경우
pair<int,int> ans={0,0};
//check ::  true :: 색약이다 , false :: 색약이 아니다.
void bfs(int x, int y,bool check){
    queue<POINT> q;
    q.push(POINT(x,y));
    //색약 [x][y][0]
    //색약이 아님 [x][y][1]
    if(check) visited[x][y][0]=true;
    else visited[x][y][1]=true;
    while(!q.empty()){
        POINT cur=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=cur.x+D[i][0];
            int ny=cur.y+D[i][1];
            if(nx<0 || ny<0 || nx>N-1 || ny>N-1) continue;
            if(check){//색약이다.
                if(visited[nx][ny][0]) continue;
                if((board[x][y]==board[nx][ny]) 
                    || (board[x][y]=='G' && board[nx][ny]=='R')
                    || (board[x][y]=='R' && board[nx][ny]=='G')){
                    visited[nx][ny][0]=true;
                    q.push(POINT(nx,ny));
                }
            }else {//색약이 아니다.
                if(visited[nx][ny][1])continue;
                if(board[x][y]==board[nx][ny]){
                    visited[nx][ny][1]=true;
                    q.push(POINT(nx,ny));
                }
            }
        }
    }
}
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        for(int j=0;j<N;j++){
            board[i][j]=str[j];
        }
    }
}
int main(){
    // (10026)
    // 적록색약
    // 적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다. 따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.

    // 크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 
    // 그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다. 
    // 또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. 
    // (색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)
    // 예를 들어, 그림이 아래와 같은 경우에

    /*
    RRRBB
    GGBBB
    BBBRR
    BBRRR
    RRRRR
    */

    // 적록색약이 아닌 사람이 봤을 때 구역의 수는 총 4개이다. 
    // (빨강 2, 파랑 1, 초록 1) 하지만, 적록색약인 사람은 구역을 3개 볼 수 있다. (빨강-초록 2, 파랑 1)
    // 그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.
    // 그림 크기 :: N (1 <= N <= 100)
    // 적록색약이 아닌 사람이 봤을 때의 구역의 개수와 적록색약인 사람이 봤을 때의 구역의 수를 공백으로 구분해 출력한다.
    input();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(visited[i][j][1]==false){
                bfs(i,j,false);
                ans.first++;
            }
            if(visited[i][j][0]==false){
                bfs(i,j,true);
                ans.second++;
            }
        }
    }
    cout<<ans.first<<' '<<ans.second<<'\n';
    return 0;
}