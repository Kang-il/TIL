#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
int N;
std::vector<int> tree[MAX];
bool visited[MAX];
int depth[MAX];
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // (11725)
    // 트리의 부모찾기
    // 루트 없는 트리가 주어진다.
    // 이 때, 트리의 루트를 1이라고 정했을 때
    // 각 노드의 부모를 구하는 프로그램을 작성하시오
    // 노드의 개수 :: N (2<=N<=100,000)
    std::cin>>N;
    for(int i=0;i<N-1;i++){
        int from,to;
        std::cin>>from>>to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    std::vector<int> ans(N+1);
    std::queue<int> q;
    q.push(1);
    visited[1]=true;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int y : tree[x]){
            if(!visited[y]){
                ans[y]=x;
                visited[y]=true;
                q.push(y);
            }
        }
    }
    for(int i=2;i<=N;i++){
        std::cout<<ans[i]<<'\n';
    }
    return 0;
}