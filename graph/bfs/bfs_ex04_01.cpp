#include <iostream>
#include <queue>
#define MAX 1000000

int map[MAX];
bool visited[MAX];
int N,K;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // (13549)
    // 숨바꼭질3
    // 수빈이의 위치 :: N (0<=N<=100,000)
    // 동생의 위치 :: K (0<=K<=100,000)
    // 수빈이의 위치가 X라면 1초 후에 X-1 또는 X-1로 이동하게 된다.
    // 순간이동을 하는 경우 2*X 위치로 이동하게 된다.
    // 현 위치에서 앞 뒤로 움직이는 경우 가중치는 1
    // 현 위치에서 순간이동 하는 경우 가중치는 0
    
    std::cin>>N>>K;

    visited[N]=true;
    map[N]=0;
    //queue 2개를 이용히여 문제를 푼다.
    std::queue<int> q1;
    std::queue<int> q2;

    q1.push(N);

    while(!q1.empty()){
        int now=q1.front();
        q1.pop();
        if(now*2<MAX){
            //순간이동 해서 가는 경우 가중치가 0이므로 q1에 넣어 먼저 탐색
            if(visited[now*2]==false){
                visited[now*2]=true;
                map[now*2]=map[now];
                q1.push(now*2);
            }
        }
        //앞뒤로 이동하는 경우 가중치가 1이므로 q2에 넣어 나중에 탐색.
        if(now+1<MAX){
            if(visited[now+1]==false){
                visited[now+1]=true;
                map[now+1]=map[now]+1;
                q2.push(now+1);
            }
        }
        if(now-1>=0){
            if(visited[now-1]==false){
                visited[now-1]=true;
                map[now-1]=map[now]+1;
                q2.push(now-1);
            }
        }
        //q1이 빌 경우 q2를 탐색하기 위해 q1에 q2를..
        if(q1.empty()){
            q1=q2;
            //queue 새로 선언
            q2=std::queue<int>();
        }
    }
    std::cout<<map[K]<<'\n';
    return 0;
}