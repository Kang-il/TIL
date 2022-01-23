#include <iostream>
#include <queue>
#include <algorithm>
#define LIMIT 10
using namespace std;
struct INFO{
    int rx,ry,bx,by,count;
};
char board[10][11];
int D[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
INFO start;
int bfs(){
    //방문여부 체크
    int visited[10][10][10][10];
    queue<INFO> q;
    //최초 구슬위치 push
    q.push(start);
    visited[start.rx][start.ry][start.bx][start.by]=1;
    int ret=-1;
    while(!q.empty()){
        INFO cur=q.front();
        q.pop();
        //10회를 넘는다면 바로 -1 return
        if(cur.count>LIMIT) return -1;
        //빨간 구슬만 구멍에 들어가 있을 경우 현재 count 를 넣어준 후 while 문 벗어남
        if(board[cur.rx][cur.ry]=='O' && board[cur.bx][cur.by]!='O'){
            ret=cur.count;
            break;
        }
        //구슬 이동 -- 기울이기
        for(int dir=0;dir<4;dir++){
            int next_rx=cur.rx;
            int next_ry=cur.ry;
            int next_bx=cur.bx;
            int next_by=cur.by;

            //빨간 구슬 이동
            while(true){
                if(board[next_rx][next_ry]!='#' && board[next_rx][next_ry]!='O'){
                    next_rx+=D[dir][0];
                    next_ry+=D[dir][1];
                }else{
                    //이동 된 위치가 벽이라면 이전 이동 위치로 이동.
                    if(board[next_rx][next_ry]=='#'){
                        next_rx-=D[dir][0];
                        next_ry-=D[dir][1];
                    }
                    break;
                }
            }
            //파란 구슬 이동
            while(true){
                if(board[next_bx][next_by]!='#' && board[next_bx][next_by]!='O'){
                    next_bx+=D[dir][0];
                    next_by+=D[dir][1];
                }else{
                    //이동된 위치가 벽이라면 이전 이동 위치로 이동.
                    if(board[next_bx][next_by]=='#'){
                        next_bx-=D[dir][0];
                        next_by-=D[dir][1];
                    }
                    break;
                }
            }
            // 파란 구슬과 빨간구슬의 위치가 같다면
            if(next_rx==next_bx && next_ry==next_by){
                //구슬 두개가 구멍에 들어간 경우가 아닐경우
                if(board[next_rx][next_ry]!='O'){
                    // ex>#.....RB# -- 두 구슬이 나란히 있는 경우 발생
                    // 두 구슬의 이동량을 비교해서 더 많이 이동한 구슬을 
                    // 직전 이동 위치로 변경해준다.
                    int dist_r=abs(next_rx-cur.rx)+abs(next_ry-cur.ry);
                    int dist_b=abs(next_bx-cur.bx)+abs(next_by-cur.by);
                    if(dist_r>dist_b){
                        next_rx-=D[dir][0];
                        next_ry-=D[dir][1];
                    }else{
                        next_bx-=D[dir][0];
                        next_by-=D[dir][1];
                    }
                }
            }
            //최소 조작이므로 방문여부 체크 후 방문 한 적 없는경우 push
            if(visited[next_rx][next_ry][next_bx][next_by]==0){
                visited[next_rx][next_ry][next_bx][next_by]=1;
                INFO next;
                next.rx=next_rx;
                next.ry=next_ry;
                next.bx=next_bx;
                next.by=next_by;
                next.count=cur.count+1;
                q.push(next);
            }
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // (13460)
    // 구슬 탈출 2 - bfs 풀이
    // 스타트링크에서 판매하는 어린이용 장난감 중에서 가장 인기가 많은 제품은 구슬 탈출이다. 
    // 구슬 탈출은 직사각형 보드에 빨간 구슬과 파란 구슬을 하나씩 넣은 다음, 
    // 빨간 구슬을 구멍을 통해 빼내는 게임이다.
    // 보드의 세로 크기는 N, 가로 크기는 M이고, 편의상 1×1크기의 칸으로 나누어져 있다. 
    // 가장 바깥 행과 열은 모두 막혀져 있고, 보드에는 구멍이 하나 있다. 
    // 빨간 구슬과 파란 구슬의 크기는 보드에서 1×1크기의 칸을 가득 채우는 사이즈이고, 각각 하나씩 들어가 있다. 
    // 게임의 목표는 빨간 구슬을 구멍을 통해서 빼내는 것이다. 이때, 파란 구슬이 구멍에 들어가면 안 된다.
    // 이때, 구슬을 손으로 건드릴 수는 없고, 중력을 이용해서 이리 저리 굴려야 한다. 
    // 왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기와 같은 네 가지 동작이 가능하다.
    // 각각의 동작에서 공은 동시에 움직인다. 
    // 빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패이다. 
    // 빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다. 빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다. 
    // 또, 빨간 구슬과 파란 구슬의 크기는 한 칸을 모두 차지한다. 
    // 기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.
    // 보드의 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램을 작성하시오.
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        for(int j=0;j<M;j++){
            board[i][j]=str[j];
            if(board[i][j]=='R'){
                start.rx=i;
                start.ry=j;
            }
            if(board[i][j]=='B'){
                start.bx=i;
                start.by=j;
            }
        }
    }
    cout<<bfs()<<'\n';
    return 0;
}