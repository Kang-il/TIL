#include <iostream>
#include <vector>
#include <string>


int check(std::vector<std::string> &board){
    int N=board.size();
    int ans=1;
    for(int i=0;i<N;i++){
        int cnt=1;
        for(int j=1;j<N;j++){
            if(board[i][j]==board[i][j-1]){
                cnt++;
            }else{
                cnt=1;
            }
            if(ans<cnt) ans=cnt;
        }
        cnt=1;
        for(int j=1;j<N;j++){
            if(board[j][i]==board[j-1][i]){
                cnt++;
            }else{
                cnt=1;
            }
        if(ans<cnt) ans=cnt;
        }
    }

    return ans;    
}

int main(){
    //(3085)
    // 사탕 게임
    // (BOMBONI)게임을 즐겨한다
    // 가장 처음 N*N 크기에 사탕을 채워 놓는다.
    // 사탕의 색은 모두 같지 않을 수 있다.
    // 사탕의 색이 다른 인접한 두칸을 고른다.
    // 그 다음 고른칸에 들어있는 사탕을 서로 교환한다.
    // 이제, 모두 같은 색으로 이루어져 있는 가장 긴 연속부분(행 또는 열)을 고른다음
    // 그 사탕을 모두 먹는다.
    // 사탕이 채워진 상태가 주어졌을 때, 먹을 수 있는 사탕의 최대개수를 구하는 프로그램을 작성하시오.

    // 다음 N개 줄에는 보드에 채워져 있는 사탕의 색상이 주어진다. 
    // 빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y로 주어진다.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin>>N;
    std::vector<std::string>board(N);

    for(int i=0;i<N;i++){
        std::cin>>board[i];
    }

    int ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(j+1<N){
                //스왑하여 현 위치의 값을 동일열의 다음행으로 바꿔준다.
                std::swap(board[i][j],board[i][j+1]);
                //체크 하여 가장 길게 먹을 수 있는 사탕의 수를 반환받는다.
                int tmp = check(board);
                //현재 저장되어있는 가장 많은 사탕의 수보다 많은 수를 반환받았을 경우 ans 값을 
                //반환받은 값으로 갱신해 준다.
                if(ans<tmp) ans=tmp;
                //변경된 위치를 원위치로 되돌리기 위해 swap을 다시 한번 수행한다.
                std::swap(board[i][j],board[i][j+1]);
            }
            if(i+1<N){
                //스왑하여 현위치의 값을 동일 행의 다음열의 값과 스왑한다.
                std::swap(board[i+1][j],board[i][j]);
                //체크하여 가장 길게 먹을 수 있는 사탕의 수를 반환 받는다.
                int tmp=check(board);
                //현재 저장되어있는 가장 많은 사탕의 수 보다 많은 수를 반환받았을 경우 ans 값을 
                //반환받은 값으로 갱신 해 준다.
                if(ans<tmp) ans=tmp;
                //변경된 위치를 원위치로 되돌리기 위해 swap을 다시 한 번 수행한다.
                std::swap(board[i+1][j],board[i][j]);
            }
        }
    }
    //최종적으로 ans 에는 가장 인접 행이나 열로 값을 이동하여 
    //가장 많이 먹을 수 있는 사탕의 갯수가 들어있다.
    //답을 출력한다.
    std::cout<<ans<<'\n';
    return 0;
}