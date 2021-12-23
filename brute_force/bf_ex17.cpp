#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> aVec;
std::vector<bool> visited;
int A[10];
void go(int idx, int start, int N, int M){
    if(idx==M){
        for(int i=0;i<M;i++){
            std::cout<<A[i];
            if(i!=M-1) std::cout<<' ';
        }
        std::cout<<'\n';
        return;
    }
    int val=-1;
    for(int i=start;i<N;i++){
        if(!visited[i] && (i==start || aVec[i]!=val)){
            val=aVec[i];
            A[idx]=aVec[i];
            go(idx+1,i+1,N,M);
        }
    }
}

int main(){
    //15664
    //N과 M (10)
    //N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는
    // 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오
    //1. N개의 자연수 중에서 M개를 고른 수열
    //2. 고른 수열은 비 내림차순 이어야 한다.
    // 길이가 K인 수열 A가 A1<=A2<=...<=Ak-1 <=Ak를 만족하면 비내림차순이라고 한다.

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N,M;
    std::cin>>N>>M;
    aVec.resize(N);
    visited.resize(N);
    for(int i=0;i<N;i++){
        std::cin>>aVec[i];
    }
    std::sort(aVec.begin(),aVec.end());
    go(0,0,N,M);
    return 0;
}