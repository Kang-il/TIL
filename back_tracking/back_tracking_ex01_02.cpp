#include <iostream>
using namespace std;

bool board[15][15];
int N;
bool check_col[15];
bool check_dig[40];
bool check_dig2[40];

bool check(int row, int col){
    if(check_col[col]) return false;
    if(check_dig[row+col]) return false;
    if(check_dig2[row-col+N]) return false;

    return true;
}

int calc(int row){
    if(row==N){
        return 1;
    }
    int cnt=0;
    for(int col=0;col<N;col++){
        if(check(row,col)){
            //해당 열. 대각선에 놓을 수 없도록 처리
            check_dig[row+col]=true;
            check_dig2[row-col+N]=true;
            check_col[col]=true;
            // 퀸을 놓는 위치
            board[row][col]=true;
            
            cnt+=calc(row+1);

            check_dig[row+col]=false;
            check_dig2[row-col+N]=false;
            check_col[col]=false;
            board[row][col]=false;
        }
    }
    return cnt;
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
    cout<<calc(0)<<'\n';
    return 0;
}