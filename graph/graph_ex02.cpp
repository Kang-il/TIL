#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

std::vector<int> a[1001];
bool check[1001];
void dfs(int node){
    check[node]=true;
    std::cout<<node<<' ';
    for(int i=0;i<a[node].size();i++){
        int next=a[node][i];
        if(!check[next]) dfs(next);
    }
}
void bfs(int start){
    std::queue<int> q;
    check[start]=true;
    q.push(start);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        std::cout<<node<<' ';
        for(int i=0;i<a[node].size();i++){
            int next=a[node][i];
            if(!check[next]){
                check[next]=true;
                q.push(next);
            }
        }
    }
}
int main(){    
    //(1260)
    //DFS와 BFS
    // 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오.
    // 단, 방문할 수 있는 정점이 여러 개인경우 정점의 번호가 작은 것을 먼저 방문하고
    // 더 이상 방문할 수 있는 점이 있는 경우 종료한다.
    // 정점 번호는 1번 부터 N번 까지다.

    //정점의 개수 N(1<=N<=1,000)
    //간선의 개수 N(1<=M<=10,000)
    //탐색을 시작할 정점의 번호 V

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int N,M,V;
    std::cin>>N>>M>>V;
    for(int i=0;i<M;i++){
        int from,to;
        std::cin>>from>>to;
        a[from].push_back(to);
        a[to].push_back(from);
    }
    for(int i=0;i<=N;i++){
        std::sort(a[i].begin(),a[i].end());
    }
    dfs(V);
    std::cout<<'\n';
    memset(check,false,sizeof(check));
    bfs(V);
    std::cout<<'\n';
    return 0;
}