#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>
using namespace std;
struct POINT{
    int t,x,y;
    POINT(int t, int x, int y):t(t),x(x),y(y){}
};
string board[8];
int D[9][2]{{0,0},{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
//[시간][row][col]
bool visited[9][8][8];
void bfs(){
   queue<POINT> q;
   q.push(POINT(0,7,0));
   visited[0][7][0]=true;
   bool ans=false;
   //8초부터 벽은 모두 내려간 상태 -- 무조건 목표지점까지 갈 수 있다.
   while(!q.empty()){
       POINT cur= q.front();
       q.pop();
       //목표지점
       if(cur.x==0 && cur.y==7){
           ans=true;
           break;
       }
       for(int i=0;i<9;i++){
           int nx=cur.x+D[i][0];
           int ny=cur.y+D[i][1];
           int nt=min(cur.t+1,8);
           //보드 범위 벗어나는 경우 건너뛰기
           if(nx<0 || ny<0 || nx>7 || ny>7) continue;
           //벽이라서 못가는 경우 건너뛰기
           if(nx-cur.t>=0 && board[nx-cur.t][ny]=='#') continue;
           //내려올 벽에 닿은 경우 건너뛰기
           if(nx-cur.t-1>=0 && board[nx-cur.t-1][ny]=='#')continue;
           if(visited[nt][nx][ny]==false){
               visited[nt][nx][ny]=true;
               q.push(POINT(nt,nx,ny));
           }
       }
   }
   if(ans) cout<<1<<'\n';
   else cout<<0<<'\n';
   return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // (16954)
    // 움직이는 미로탈출
    // 욱제는 학교 숙제로 크기가 8×8인 체스판에서 탈출하는 게임을 만들었다. 
    // 체스판의 모든 칸은 빈 칸 또는 벽 중 하나이다. 
    // 욱제의 캐릭터는 가장 왼쪽 아랫 칸에 있고, 이 캐릭터는 가장 오른쪽 윗 칸으로 이동해야 한다.

    // 이 게임의 특징은 벽이 움직인다는 점이다. 
    // 1초마다 모든 벽이 아래에 있는 행으로 한 칸씩 내려가고, 가장 아래에 있어서 아래에 행이 없다면 벽이 사라지게 된다. 
    // 욱제의 캐릭터는 1초에 인접한 한 칸 또는 대각선 방향으로 인접한 한 칸으로 이동하거나, 현재 위치에 서 있을 수 있다. 
    // 이동할 때는 빈 칸으로만 이동할 수 있다.

    // 1초 동안 욱제의 캐릭터가 먼저 이동하고, 그 다음 벽이 이동한다. 
    // 벽이 캐릭터가 있는 칸으로 이동하면 더 이상 캐릭터는 이동할 수 없다.

    // 욱제의 캐릭터가 가장 오른쪽 윗 칸으로 이동할 수 있는지 없는지 구해보자.

    for(int i=0;i<8;i++) cin>>board[i];
    bfs();
    return 0;
}
