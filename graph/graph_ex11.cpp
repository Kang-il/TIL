#include <iostream>
#include <vector>
#include <queue>
#define MAX 3000

int N;
std::vector<int> route[MAX];
int check[MAX]; //0 :: 방문하지 않았다. 1 :: 방문했다. 2 :: 사이클에 포함
int dist[MAX];

int go(int x, int p){
    //-2 :: 사이클을 찾았지만 포함되지 않는다.
    //-1 :: 사이클을 찾지 못했다.
    //0 ~ N-1 :: 사이클을 찾았고 시작 인덱스다.
    if(check[x]==1) return x;
    check[x]=1;
    for(int y : route[x]){
        if(y==p) continue;
        int res=go(y,x);
        if(res==-2) return -2;
        if(res>=0){
            check[x]=2;
            if(x==res) return -2;
            else return res;
        }
    }
    return -1;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    //(16947)
    // 서울지하철 2호선
    /*
        지하철 2호선에는 51개의 역이 있고, 역과 역 사이를 연결하는 구간이 51개 있다. 
        즉, 정점이 51개이고, 양방향 간선이 51개인 그래프로 나타낼 수 있다. 
        2호선은 순환선 1개와 2개의 지선으로 이루어져 있다. 
        한 역에서 출발해서 계속 가면 다시 출발한 역으로 돌아올 수 있는 노선을 순환선이라고 한다. 
        지선은 순환선에 속하는 한 역에서 시작하는 트리 형태의 노선이다.
        두 역(정점) 사이의 거리는 지나야 하는 구간(간선)의 개수이다. 
        역 A와 순환선 사이의 거리는 A와 순환선에 속하는 역 사이의 거리 중 최솟값이다.
        지하철 2호선과 같은 형태의 노선도가 주어졌을 때, 각 역과 순환선 사이의 거리를 구해보자.
    */
    std::cin>>N;
    //모든 정점이 순환선으로 부터 얼마나 떨어져 있는지
    //1. 순환선 찾기
    //2. 순환선으로부터 얼마나 떨어져 있는지.
    for(int i=0;i<N;i++){
        int from,to;
        std::cin>>from>>to;
        from--,to--;
        route[from].push_back(to);
        route[to].push_back(from);
    }

    go(0,-1);
    std::queue<int> q;
    for(int i=0;i<N;i++){
        if(check[i]==2){
            dist[i]=0;
            q.push(i);
        }else{
            dist[i]=-1;
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int y : route[x]){
            if(dist[y]==-1){
                q.push(y);
                dist[y]=dist[x]+1;
            }
        }
    }
    for(int i=0;i<N;i++){
        std::cout<<dist[i]<<' ';
    }
    std::cout<<'\n';

    return 0;
}