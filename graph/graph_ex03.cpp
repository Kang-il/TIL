#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> aVec[1001];
bool visited[1001];
void dfs(int node){
    visited[node]=true;
    for(int i=0;i<aVec[node].size();i++){
        int next=aVec[node][i];
        if(!visited[next]) dfs(next);
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //(11724)
    //연결요소의 개수
    // 방향 없는 그래프가 주어졌을 때, 연결요소(Connected Component)의
    // 개수를 구하는 프로그램을 작성하시오
    // 정점의 개수 :: N (1<=N<=1,000)
    // 간선의 개수 :: M (0<=M<=N*(N-1)/2)
    int N,M;
    std::cin>>N>>M;
    for(int i=0;i<M;i++){
        int from,to;
        std::cin>>from>>to;
        aVec[from].push_back(to);
        aVec[to].push_back(from);
    }

    int component=0;
    for(int i=1;i<=N;i++){
        if(visited[i]) continue;
        dfs(i);
        component+=1;
    }

    std::cout<<component<<'\n';

    return 0;
}