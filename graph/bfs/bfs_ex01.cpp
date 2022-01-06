#include <iostream>
#include <queue>
#define MAX 100001

bool visited[MAX+1];
int map[MAX+1];
int D[3]{1,-1,2};
int N,K;
int main(){
    //(1697)
    // 숨바꼭질
    // 수빈이의 위치 :: N (0<=N<=100,000)
    // 동생의 위치 :: K (0<=K<=100,000)
    // 수빈이의 위치가 X라면 1초 후에 X-1 또는 X-1로 이동하게 된다.
    // 순간이동을 하는 경우 2*X 위치로 이동하게 된다.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>N>>K;
    std::queue<int> q;
    visited[N]=true;
    map[N]=0;
    q.push(N);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<3;i++){
            int nx=x;
            if(i<2){
                nx+=D[i];
            }else{
                nx*=D[i];
            }
            if(nx < 0 || nx>MAX-1) continue;
            if(visited[nx])continue;
            visited[nx]=true;
            map[nx]=map[x]+1;
            q.push(nx);
        }
    }
    std::cout<<map[K]<<'\n';
    return 0;
}