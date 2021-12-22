#include <iostream>

int A[10];
void go(int idx,int N,int M){
    if(idx==M){
        for(int i=0;i<M;i++){
            std::cout<<A[i];
            if(i!=M-1) std::cout<<" ";
        }
        std::cout<<'\n';
        return;
    }

    for(int i=1;i<=N;i++){
        A[idx]=i;
        go(idx+1,N,M);
    }
}
int main(){
    //(15652)
    //N과 M(3)
    //자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오
    // 1부터 N까지 자연수 중에서 M개를 고른 수열
    // 같은 수를 여러번 골라도 된다.
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    int N,M;
    std::cin>>N>>M;
    go(0,N,M);
    return 0;
}
