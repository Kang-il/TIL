#include<iostream>
using namespace std;
int N,M;
int board[500][500];
bool visited[500][500];
int D[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
int ans=0;
void go(int x, int y, int sum, int cnt){
    if(cnt==4){
        if(ans<sum)ans = sum;
        return;
    }
    if(x<0 || x>=N || y<0 || y>=M) return;
    if(visited[x][y])return;
    visited[x][y]=true;
    for(int i=0;i<4;i++){
        go(x+D[i][0],y+D[i][1],sum+board[x][y],cnt+1);
    }
    visited[x][y]=false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // (14500)
    // 테트로미노
     /*
         폴리오미노란 크기가 1×1인 정사각형을 여러 개 이어서 붙인 도형이며, 다음과 같은 조건을 만족해야 한다.
         1. 정사각형은 서로 겹치면 안 된다.
         2. 도형은 모두 연결되어 있어야 한다.
         3. 정사각형의 변끼리 연결되어 있어야 한다. 즉, 꼭짓점과 꼭짓점만 맞닿아 있으면 안 된다.
         
         정사각형 4개를 이어 붙인 폴리오미노는 테트로미노라고 하며, 다음과 같은 5가지가 있다.
         이미지 참고
         https://www.acmicpc.net/problem/14500
         아름이는 크기가 N×M인 종이 위에 테트로미노 하나를 놓으려고 한다. 
         종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 정수가 하나 쓰여 있다.
         테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.

         테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며, 회전이나 대칭을 시켜도 된다.
         첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)

         둘째 줄부터 N개의 줄에 종이에 쓰여 있는 수가 주어진다. 
         i번째 줄의 j번째 수는 위에서부터 i번째 칸, 
         왼쪽에서부터 j번째 칸에 쓰여 있는 수이다. 입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.
     */
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            go(i,j,0,0);
            if(j+2 < M){
                int tmp= board[i][j]+board[i][j+1]+board[i][j+2];
                if(i-1>=0){
                    int tmp2=tmp+board[i-1][j+1];
                    if(ans<tmp2) ans=tmp2;
                }
                if(i+1<N){
                    int tmp2=tmp+board[i+1][j+1];
                    if(ans<tmp2) ans=tmp2;
                }
            }
            if(i+2<N){
                int tmp=board[i][j]+board[i+1][j]+board[i+2][j];
                if(j+1<M){
                    int tmp2=tmp+board[i+1][j+1];
                    if(ans<tmp2) ans=tmp2;
                }
                if(j-1>=0){
                    int tmp2=tmp+board[i+1][j-1];
                    if(ans<tmp2) ans=tmp2;
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}