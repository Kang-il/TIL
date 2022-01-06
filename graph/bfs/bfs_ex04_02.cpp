#include <iostream>
#include <deque>

#define MAX 1000000
bool visited[MAX];
int N,K;
int map[MAX];
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

    //deque 를 이용한 문제 풀이
    std::deque<int> dq;
    dq.push_back(N);

    while(!dq.empty()){
        int now=dq.front();
        dq.pop_front();
        if(now*2<MAX){
            if(visited[now*2]==false){
                //우선순위가 있는 순간이동은 앞으로 push
                dq.push_front(now*2);
                visited[now*2]=true;
                map[now*2]=map[now];
            }
        }
        //순간이동보다 우선순위가 아래인 앞뒤 이동은 뒤로 push
        if(now-1>=0){
            if(visited[now-1]==false){
                dq.push_back(now-1);
                visited[now-1]=true;
                map[now-1]=map[now]+1;
            }
        }
        if(now+1 < MAX){
            if(visited[now+1]==false){
                dq.push_back(now+1);
                visited[now+1]=true;
                map[now+1]=map[now]+1;
            }
        }
    }

    std::cout<<map[K]<<'\n';
    return 0;
}