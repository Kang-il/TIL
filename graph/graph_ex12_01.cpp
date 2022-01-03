#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000

int N;
int parent[MAX];
std::vector<int> graph[MAX];
bool visited[MAX];
int order[MAX];

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

    for(int i=0;i<N;i++){
        std::cin>>order[i];
        order[i]-=1;
    }

    std::queue<int> q;
    q.push(0);
    visited[0]=true;

    int m=1;
    for(int i=0;i<N;i++){
        if(q.empty()){
            std::cout<<0<<'\n';
            return 0;
        }
        
        int x=q.front(); 
        q.pop();

        if(x!=order[i]){
            std::cout<<0<<'\n';
        }
        int cnt=0;
        for(int j=0;j<graph[x].size();j++){
            int y=graph[x][j];
            if(!visited[y]){
                parent[y]=x;
                cnt++;
            }
        }
        for(int j=0;j<cnt;j++){
            if(m+j>=N || parent[order[m+j]]!=x){
                std::cout<<0<<'\n';
                return;
            }
            q.push(order[m+j]);
            visited[order[m+j]]=true;
        }
        m+=cnt;
    }
    std::cout<<1<<'\n';
    return 0;
}