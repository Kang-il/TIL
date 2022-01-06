#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

#define MAX 1001
int board[MAX][MAX];
int S;
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    // (14226)
    // 이모티콘 
    // 스마일 이모티콘을 S개 보내려고 한다.
    // 3가지 연산만을 이용해서 스마일 이모티콘 S개를 만드려고 한다.
    // 1. 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
    // 2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기한다.
    // 3. 화면에 있는 이모티콘 중 하나를 삭제한다.
    // 모든 연산은 1초가 걸린다.
    // 클립보드 복사 시 이전 클립보드에 있는 내용은 덮어쓰기가 된다.
    // 클립보드가 비어있는 상태에는 붙여넣기 할 수 없으며, 일부만 클립보드에 복사할 수 없다.
    // 또한 클립보드에 있는 이모티콘 중 일부를 삭제할 수 없다.
    // 화면에 이모티콘을 붙여넣기 하면 클립보드에 있는 이모티콘으 ㅣ 개수가 화면에 추가된다.
    // 이모티콘을 S개 만들기 위해 필요한 시간의 최소값을 추가한다.

    std::cin>>S;
    memset(board,-1,sizeof(board));
    board[1][0]=0;
    std::queue<std::pair<int,int>> q;
    q.push(std::make_pair(1,0));
    while(!q.empty()){
        // s :: 화면에 써져있는 이모티콘 개수
        // c :: 클립보드에 복사되어 있는 이모티콘 개수
        int s,c;
        std::tie(s,c)=q.front();
        q.pop();
        if(board[s][s]==-1){//클립보드에 복사하는 경우
            board[s][s]=board[s][c]+1;
            q.push(std::make_pair(s,s));
        }
        if(s+c <= S && board[s+c][c]==-1){//화면에 클립보드의 이모티콘 붙여넣기 하는 경우
            board[s+c][c]=board[s][c]+1;
            q.push(std::make_pair(s+c,c));
        }
        if(s-1 >= 0 && board[s-1][c]==-1){//화면의 이모티콘 하나를 지우는 경우
            board[s-1][c]=board[s][c]+1;
            q.push(std::make_pair(s-1,c));
        }
    }

    int ans=-1;
    for(int i=0;i<=S;i++){
        if(board[S][i]!=-1){
            if(ans==-1 || ans>board[S][i]){
                ans=board[S][i];
            }
        }
    }
    std::cout<<ans<<'\n';
    return 0;
}