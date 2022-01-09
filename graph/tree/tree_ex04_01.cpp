#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 100001
struct Edge{
    int to;
    int cost;
    Edge(int to, int cost) : to(to),cost(cost){
    }
};
int N;
std::vector<Edge> tree[MAX];
bool visited[MAX];
int dist[MAX];
void bfs(int start){
    memset(dist,0,sizeof(dist));
    memset(visited,false,sizeof(visited));
    std::queue<int> q;
    visited[start]=true;
    q.push(start);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<tree[x].size();i++){
            Edge &e=tree[x][i];
            if(visited[e.to]==false){
                //거리 x비용 + edge 비용
                dist[e.to]=dist[x]+e.cost;
                q.push(e.to);
                visited[e.to]=true;
            }
        }
    }
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // (1167)
    // 트리의 지름
    // 트리의 지름이란.
    // 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다.
    // 트리의 지름을 구하는 프로그램을 작성하시오

    // 정점의 개수 :: N (2<= N <= 100,000)
    // 정점의 번호가 주어지고 간선의 정보를 의미하는 정수가 2개씩
    // 첫 번째 값 :: 정점의 번호 , 두 번째 값 :: 그 정점 까지의 거리
    // 각 줄의 마지막엔 -1이 주어진다.
    std::cin>>N;
    for(int i=1;i<=N;i++){
        int x;
        std::cin>>x;
        while(true){
            int y,z;
            std::cin>>y;
            if(y==-1) break;
            std::cin>>z;
            tree[x].push_back(Edge(y,z));
        }
    }
    bfs(1);
    int start=1;
    for(int i=2;i<=N;i++){
        if(dist[i]>dist[start]){
            start=i;
        }
    }
    bfs(start);
    int ans=dist[1];
    for(int i=2;i<=N;i++){
        if(ans<dist[i]){
            ans=dist[i];
        }
    }
    std::cout<<ans<<'\n';
    return 0;
}