#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> nVec;
std::vector<bool> visited;
int A[10];
void go(int idx, int start, int N,int M){
    if(idx==M){
        for(int i=0;i<M;i++){
            std::cout<<A[i];
            if(i!=M-1)std::cout<<" ";
        }
        std::cout<<'\n';
        return;
    }

    for(int i=start;i<N;i++){
        if(visited[i]) continue;
        visited[i]=true;
        A[idx]=nVec[i];
        go(idx+1,i+1,N,M);
        visited[i]=false;
    }
}
int main(){
    //(15655)
    // N과 M(6)
    // N개의 자연수와 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는
    // 프로그램을 작성하시오.
    //1. N개의 자연수 중에서 M개를 고른 수열
    //2. 고른 수열은 모두 오름차순 이어야 한다.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N,M;
    std::cin>>N>>M;

    nVec.resize(N);
    visited.resize(M);
    for(int i=0;i<N;i++){
        std::cin>>nVec[i];
    }
    std::sort(nVec.begin(),nVec.end());
    go(0,0,N,M);

    return 0;
}