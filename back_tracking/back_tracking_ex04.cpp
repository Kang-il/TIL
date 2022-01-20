#include <iostream>
using namespace std;
int R,C;
char board[20][20];
bool visited[26];
int D[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
int dfs(int x, int y){
    int ans=0;
    for(int i=0;i<4;i++){
        int nx=x+D[i][0];
        int ny=y+D[i][1];
        //보드 범위를 벗어난 경우
        if(nx<0 || ny<0 || nx>R-1 || ny>C-1) continue;
        //이미 방문 한 적 있는 알파벳일 경우
        if(visited[board[nx][ny]-'A']) continue;
        
        visited[board[nx][ny]-'A']=true;
        int tmp=dfs(nx,ny);
        if(ans<tmp)ans = tmp;
        visited[board[nx][ny]-'A']=false;
    }
    return ans+1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //(1987)
    // 알파벳
    // 세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다. 
    // 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.

    // 말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 
    // 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다. 
    // 즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.

    // 좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 
    // 말이 지나는 칸은 좌측 상단의 칸도 포함된다.
    // R,C :: 보드 크기 (1<=R,C<=20)
    cin>>R>>C;   
    for(int i=0;i<R;i++){
        string str;
        cin>>str;
        for(int j=0;j<C;j++){
            board[i][j]=str[j];
        }
    }
    visited[board[0][0]-'A']=true;
    cout<<dfs(0,0)<<'\n';
    return 0;
}