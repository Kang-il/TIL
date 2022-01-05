#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100000

std::vector<int> graph[MAX];
bool visited[MAX];
int N;
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //(16940)
    // BFS 스페셜 저지
    // 1. 큐에 시작 정점을 넣는다. 이 문제에서 시작정점은 1이다. 1을 방문했다고 처리한다
    // 2. 큐가 비어 있지 않은동안 다음을 반복한다.
    //      2-1. 큐에 들어있는 첫 정점을 큐에서 꺼낸다. 이 정점을 x라고 하자.
    //      2-2. x와 연결되어 있으면, 아직 방문하지 않은 정점 y를 모두 큐에 넣는다.
    //           모든 y를 방문했다고 처리한다.
    // 2-2 단계에서 방문하지 않은 정점을 방문하는 순서는 중요하지 않다,
    // 따라서 BFS의 결과는 여러가지가 나올 수 있다.
    // 트리가 주어졌을 때, 올바른 BFS 방문 순서인지 구해보자
    // 정점의 수 N :: 2<=N=100,000
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
        std::sort(graph[i].begin(),graph[i].end(),[&](const int &u, const int &v){
            return order[u]<order[v];
        });
    }
    std::vector<int> bfs_order;
    std::queue<int> q;
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        bfs_order.push_back(x);
        for(int y:graph[x]){
            if(visited[y]==false){
                q.push(y);
                visited[y]=true;
            }
        }
    }

    if(bfs_order==b){
        std::cout<<1<<'\n';
    }else{
        std::cout<<0<<'\n';
    }
    return 0;
}