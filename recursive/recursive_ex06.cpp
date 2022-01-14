#include <iostream>
#include <vector>
using namespace std;
struct Coin{
    int x,y;
    Coin(int x, int y):x(x),y(y){}
};
int N,M;
char board[20][20];
//동전 이동규칙 -- 상하좌우
int D[4][2]{{1,0},{-1,0},{0,1},{0,-1}};

int calc(int step, int x1,int y1, int x2, int y2){
    //10번 보다 많은 버튼을 눌러야 한다면 -1 출력
    if(step==11) return -1;
    bool fall1=false;
    bool fall2=false;
    // 보드를 벗어나는 경우 true를 받아줌
    if(x1<0 || x1>=N || y1<0 || y1>=M) fall1=true;
    if(x2<0 || x2>=N || y2<0 || y2>=M) fall2=true;
    //두 동전이 떨어지는 경우는 없으므로 -1 반환
    if(fall1&&fall2) return -1;
    //두 동전 중 한 동전만 떨어졌다면 step(동전 이동 횟수) 반환
    if(fall1 || fall2) return step;
    int ans=-1;
    for(int k=0;k<4;k++){
        int nx1=x1+D[k][0];
        int ny1=y1+D[k][1];
        int nx2=x2+D[k][0];
        int ny2=y2+D[k][1];
        // 이동시 보드 범위내에 존재하고 이동하려는 위치가 벽이라면 이동 X
        if(nx1>=0 && nx1 < N && ny1>=0 && ny1<M && board[nx1][ny1]=='#'){
            nx1=x1;
            ny1=y1;
        }
        if(nx2>=0 && nx2 < N && ny2>=0 && ny2<M && board[nx2][ny2]=='#'){
            nx2=x2;
            ny2=y2;
        }
        int tmp=calc(step+1,nx1,ny1,nx2,ny2);
        //-1 반환시 조건불만족이므로 continue
        if(tmp==-1) continue;
        //최소값
        if(ans==-1 || ans>tmp){
            ans=tmp;
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // (16197)
    // 두 동전
    // N*M 크기의 보드와 4개의 버튼으로 이루어진 게임이 있다.
    // 보드는 1*1 크기의 정사각형 칸으로 나누어져 있고
    // 각각의 칸은 비어있거나, 벽이다. 두 개의 빈칸에는 동전이 하나씩 놓여져 있고, 두 동전의 위치는 다르다.
    // 버튼은 왼쪽 오른쪽 위 아래와 같이 4가지가 있다. 버튼을 누르면 두 동전이 버튼에 쓰여있는 방향으로 동시에 이동하게 된다.
    // 1. 동전이 이동하려는 칸이 벽이면, 동전은 이동하지 않는다.
    // 2. 동전이 이동하려는 방향에 칸이 없으면 동전은 보드 바깥으로 떨어진다.
    // 3. 그 외의 경우에는 이동하려는 방향으로 한 칸 이동한다.이동하려는 칸에 동전이 있는 경우에도 한 칸 이동한다.
    // 보드의 상태 
    // o : 동전
    // . : 빈칸
    // # : 벽
    // 동전 중 하나만 떨어뜨리기 위해 눌러야 하는 버튼의 최소횟수를 출력한다.
    // 만약 두 동전을 떨어뜨릴 수 없거나, 버튼을 10번보다 많이 눌러야 한다면 -1을 출력한다.
    // 보드의 크기 :: N,M (1<=N,M<=20)
    cin>>N>>M;
    
    vector<Coin> coins;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        for(int j=0;j<M;j++){
            board[i][j]=str[j];
            // 현재 입력된 보드에 동전이 있다면
            if(board[i][j]=='o'){
                //push_back
                coins.push_back(Coin(i,j));
            }
        }
    }
    // 동전은 항상 두개.
    // 해당 동전의 위치
    cout<<calc(0,coins[0].x,coins[0].y,coins[1].x,coins[1].y)<<'\n';
    return 0;
}