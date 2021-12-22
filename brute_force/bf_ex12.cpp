#include <iostream>
#include <vector>
#include <algorithm>

int B[10];
std::vector<int> A;
std::vector<bool> visited;
void go(int idx, int N, int M){
    if(idx==M){
        for(int i=0;i<M;i++){
            std::cout<<B[i];
            if(i!=M-1) std::cout<<' ';
        }
        std::cout<<'\n';
        return;
    }

    for(int i=0;i<N;i++){
        if(visited[i]) continue;
        visited[i]=true;
        B[idx]=A[i];
        go(idx+1,N,M);
        visited[i]=false;
    }
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    //(15654)
    // N과 M(5)
    // N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는
    // 프로그램을 작성하시오
    // 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 
    // 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
    
    // 풀이방식
    // 이전과 다르게 1-N까지 연속된 수가 아닌 숫자가 정해지고 그것으로 수열을 만들어야 하므로
    // 주어진 수를 저장할 수 있는 vector와 visited(해당 갯수에 맞게)를 선언해 준다. 
    int N,M;
    std::cin>>N>>M;

    A.resize(N);
    visited.resize(N);
    for(int i=0;i<N;i++){
        std::cin>>A[i];
    }

    std::sort(A.begin(),A.end());
    go(0,N,M);
    return 0;
}