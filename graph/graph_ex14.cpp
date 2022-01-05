#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000

int N;
bool visited[MAX];
std::vector<int> graph[MAX];
std::vector<int> dfs_order;
void dfs(int node){
    if(visited[node]) return;
    dfs_order.push_back(node);
    visited[node]=true;
    for(int i=0;i<graph[node].size();i++){
        int y=graph[node][i];
        dfs(y);
    }
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //(16964)
    //DFS 스페셜 저지
    // BOJ에서 정답이 여러가지인 경우에는 스페셜 저지를 사용한다. 
    // 스페셜 저지는 유저가 출력한 답을 검증하는 코드를 통해서 정답 유무를 결정하는 방식이다. 
    // 오늘은 스페셜 저지 코드를 하나 만들어보려고 한다.
    // 트리가 주어졌을 때, 올바른 DFS 방문 순서인지 구해보자.
    // 정점의 수 :: N (2<=N<=100,000)
    
    std::cin>>N;
    for(int i=0;i<N-1;i++){
        int from,to;
        std::cin>>from>>to;
        from--,to--;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    std::vector<int> b(N);
    std::vector<int> order(N);
    for(int i=0;i<N;i++){
        std::cin>>b[i];
        b[i]-=1;
        order[b[i]]=i;
    }
    for(int i=0;i<N;i++){
        sort(graph[i].begin(),graph[i].end(),[&](const int &u,const int &v){
            return order[u]<order[v];
        });
    }
    dfs(0);
    if(dfs_order == b){
        std::cout<<1<<'\n';
    }else{
        std::cout<<0<<'\n';
    }
    return 0;
}