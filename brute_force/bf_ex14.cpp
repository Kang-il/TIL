#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> aVec;
int A[10];
void go(int idx, int N, int M){
    if(idx==M){
        for(int i=0;i<M;i++){
            std::cout<<A[i];
            if(i!=M-1) std::cout<<" ";
        }
        std::cout<<'\n';
        return;
    }
    for(int i=0;i<N;i++){
        A[idx]=aVec[i];
        go(idx+1,N,M);
    }
}
int main(){
    //(15656)
    // N과 M(7)
    // N개의 자연수와 자연수 M이 주어졌을 때, 아래조건을 만족하는 길이가
    // M인 수열을 모두 구하는 프로그램을 작성하시오.
    // N개의 자연수는 모두 다른 수이다.
    // N개의 자연수 중에서 M개를 고른 수열.
    
    // 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다.
    // 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분하여 출력
    // 수열은 사전순으로 증가하는 순서로 출력해야 한다.

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N,M;
    std::cin>>N>>M;
    aVec.resize(N);

    for(int i=0; i<N;i++){
        std::cin>>aVec[i];
    }
    std::sort(aVec.begin(),aVec.end());

    go(0,N,M);
    return 0;
}