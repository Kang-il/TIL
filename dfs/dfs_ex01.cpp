#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
//최대 20 20
int N,ret;
struct BOARD{
    int map[20][20];
    //시계방향 90도 회전
    void rotate(){
        int temp[20][20];
        for(int x=0;x<N;++x){
            for(int y=0;y<N;++y){
                temp[x][y]=map[N-y-1][x];
            }
        }
        for(int x=0;x<N;++x){
            for(int y=0;y<N;++y){
                map[x][y]=temp[x][y];
            }
        }
    }
    // 보드에 있는 최대 값 반환
    int get_max(){
        int ret=0;
        for(int x=0;x<N;++x){
            for(int y=0;y<N;++y){
                if(ret<map[x][y]) ret=map[x][y];
            }
        }
        return ret;
    }
    // 블록을 위로 옮기는 메서드
    // 같은 수 이면서 합쳐진 적이 없는 경우 합쳐준다.
    void up(){
        int temp[20][20];
        for(int y=0 ; y<N ; ++y){
            int flag=0,target=-1;
            for(int x=0 ; x<N ; ++x){
                if(map[x][y]==0) continue;
                if(flag==1 && map[x][y] == temp[target][y]){
                    temp[target][y]*=2, flag=0;
                }else{
                    temp[++target][y]=map[x][y],flag=1;
                }
            }
            for(++target ; target<N ; ++target){
                temp[target][y]=0;
            }
        }
         for(int x=0;x<N;++x){
            for(int y=0;y<N;++y){
                map[x][y]=temp[x][y];
            }
        }
    }
};
void dfs(BOARD cur, int count){
    if(count==5){//5번 이동.
        int candi=cur.get_max();
        if(ret<candi) ret=candi;
        return;
    }
    for(int dir=0;dir<4;++dir){
        BOARD next= cur;
        next.up();
        dfs(next,count+1);
        cur.rotate();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //(12100)
    // 2048 (Easy)
    // 2048 게임은 4×4 크기의 보드에서 혼자 즐기는 재미있는 게임이다.
    // 이 게임에서 한 번의 이동은 보드 위에 있는 전체 블록을 상하좌우 네 방향 중 하나로 이동시키는 것이다.
    // 이때, 같은 값을 갖는 두 블록이 충돌하면 두 블록은 하나로 합쳐지게 된다. 
    // 한 번의 이동에서 이미 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다. 
    // (실제 게임에서는 이동을 한 번 할 때마다 블록이 추가되지만, 이 문제에서 블록이 추가되는 경우는 없다)
    // https://www.acmicpc.net/problem/12100 -- 규칙참고
    // 이 문제에서 다루는 2048 게임은 보드의 크기가 N×N 이다. 
    // 보드의 크기와 보드판의 블록 상태가 주어졌을 때, 최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값을 구하는 프로그램을 작성하시오.
    
    BOARD board;
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board.map[i][j];
        }
    }
    dfs(board, 0);
    cout<<ret<<'\n';
    return 0;
}