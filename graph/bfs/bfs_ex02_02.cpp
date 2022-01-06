#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#define MAX 100001

bool visited[MAX];
int map[MAX];
int from[MAX];
int D[3]{1,-1,2};
int N,K;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //(13913)
    // 숨바꼭질4
    // 수빈이의 위치 :: N (0<=N<=100,000)
    // 동생의 위치 :: K (0<=K<=100,000)
    // 수빈이의 위치가 X라면 1초 후에 X-1 또는 X-1로 이동하게 된다.
    // 순간이동을 하는 경우 2*X 위치로 이동하게 된다.
    // 모든 행동의 가중치는 1초
    // 어떤 쵀소 경로로 이동하여 수빈이가 동생의 위치에 도달했는지 출력 할 것
    // (여러가지 경로가 있지만 1개만 출력)
    
    std::cin>>N>>K;

    std::queue<int> q;
    std::vector<int> order;
    q.push(N);
    visited[N]=true;
    order.push_back(N);
    int diff=std::abs(N-K);
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
            if(nx<0 || nx>MAX-1) continue;
            if(visited[nx])continue;
            order.push_back(nx);
            visited[nx]=true;
            q.push(nx);
            map[nx]=map[x]+1;
            // 역추적하기 위해서 이전의 인덱스번호를 현재 인덱스에 넣어준다.
            from[nx]=x;
        }
    }
    std::cout<<map[K]<<'\n';

    //스택을 이용한 출력
    std::stack<int> ans;
    for(int i=K ; i!=N ; i=from[i]){
        ans.push(i);
    }
    ans.push(N);
    while(!ans.empty()){
        std::cout<<ans.top()<<' ';
        ans.pop();
    }
    std::cout<<'\n';

    return 0;
}