#include <iostream>
using namespace std;

bool visited[15][15];
int N;
int ans=0;


bool check(int row, int col){
    for(int i=0;i<N;i++){
        if(i==row) continue;
        if(visited[i][col])return false;
    }
 
    for(int x=row-1,y=col-1 ;x>=0 && y>=0 ; x--,y--){
        if(visited[x][y]) return false;
    }

    for(int x=row-1,y=col+1 ; x>=0 && y<N ; x--,y++){
        if(visited[x][y])return false;
    }
    return true;
}
void calc(int row){
    if(row==N){
        ans++;
        return;
    }
    for(int col=0;col<N;col++){
        visited[row][col]=true;
        if(check(row,col)){
            calc(row+1);
        }
        visited[row][col]=false;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //(9963)
    // N-Queen
    // N-Queen 문제는 크기가 N*N 인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제다.
    // N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 문제를 작성하시오
    // N :: 1<=N<=15

    //1. 퀸의 가로 세로 대각선에는 다른 퀸이 올 수 없다 == 한 줄에 퀸 하나
    //2. x축에 퀸을 하나 놓고, x+1 줄에 퀸을 놓을 수 있는 자리를 찾는다
    //3. 마지막 줄(N-1)에 퀸을 놓고나면 ans을 +1해준다.
    cin>>N;
    calc(0);
    cout<<ans<<'\n';
    return 0;
}