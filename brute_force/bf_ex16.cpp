#include <iostream>
#include <set>
#include <vector>

std::vector<int> numVec;
std::vector<bool> visited;
int A[10];

void go(int idx,int N,int M){
    if(idx==M){
        for(int i=0;i<M;i++){
            std::cout<<A[i];
            if(i!=M-1) std::cout<<' ';
        }
        std::cout<<'\n';
        return;
    }
    int val=-1;
    for(int i=0;i<N;i++){
        if(!visited[i] && ( i==0 || val!=numVec[i])){
            visited[i]=true;
            val=numVec[i];
            A[idx]=numVec[i];
            go(idx+1,N,M);
            visited[i]=false;
        }
    }

}

int main(){
    //(15663)
    //N과 M(9)
    //N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는
    //프로그램을 작성하시오
    // N개의 자연수 중에서 M개를 고른 수열
    // 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다.
    // 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
    // 수열은 사전순으로 증가하는 순서로 출력해야 한다.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N,M;
    std::cin>>N>>M;
    numVec.resize(N);
    visited.resize(N);
    for(int i=0;i<N;i++){
        std::cin>>numVec[i];
    }
    std::sort(numVec.begin(),numVec.end());
    go(0,N,M);
    return 0;
}