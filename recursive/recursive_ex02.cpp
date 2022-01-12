#include <iostream>

int N;
int S;
int board[20];
int ans=0;
void go(int idx, int sum){
    if(idx==N){
        if(sum==S){
            ans+=1;
        }
        return;
    }
    go(idx+1,sum+board[idx]);
    go(idx+1,sum);
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //(1182)
    // 부분수열의 합
    // N개의 정수르 이루어진 수열이 있을 때, 
    // 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이
    // S가 되는 경우의 수를 구하는 프로그램을 작성하시오.
    std::cin>>N>>S;
    for(int i=0;i<N;i++){
        std::cin>>board[i];
    }
    go(0,0);
    //구하고자 하는 값이 0이라면 
    //아무것도 고르지 않는 부분수열도 있으므로
    // -1을 해주면 된다. 
    if(S==0) ans-=1;
    std::cout<<ans<<'\n';

    return 0;
}
