#include <iostream>
#include <vector>
#include <cstring>
#include <string>
std::vector<int> aVec[20001];
int color[20001];
void dfs(int node, int c){
    color[node]=c;
    for(int i=0;i<aVec[node].size();i++){
        int next=aVec[node][i];
        if(color[next]==0){
            dfs(next,3-c);
        }
    }
}

bool isBipartiteGraph(int V){
    for(int i=1;i<=V;i++){
        int size=aVec[i].size();
        for(int j=0;j<size;j++){
            int next=aVec[i][j];
            if(color[i]==color[next]) return false;
        }
    }
    return true;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //(1707)
    // 이분그래프
    // 그래프의 정점의 집합을 둘로 분할하여, 각 집합에 속한 정점끼리는 서로 인접하지 않도록
    // 분할 할 수 있을 때 그러한 그래프를 이분 그래프(Bipartite Graph)라 부른다.
    // 그래프가 입력으로 주어졌을 때, 이 그래프가 이분그래프인지 아닌지 판별하는 프로그램을 작성하시오.

    // K :: 테스트 케이스 개수 (2<=K<=5)
    // V :: 정점의 개수 (1<=V<=20,000)
    // E :: 간선의 개수 (1<=E<=200,000)
    int K;
    std::cin>>K;
    while(K--){
        int V,E;
        std::cin>>V>>E;
        for(int i=1; i<=V;i++){
            color[i]=0;
            aVec[i].clear();
        }
        for(int i=0;i<E;i++){
            int from, to;
            std::cin>>from>>to;
            aVec[from].push_back(to);
            aVec[to].push_back(from);
        }

        for(int i=1;i<=V;i++){
            if(color[i])continue;
            dfs(i,1);
        }
        bool ok=isBipartiteGraph(V);
        
        std::string ans = ok ? "YES" : "NO" ;
        std::cout<<ans<<'\n'; 
    }

    return 0;
}