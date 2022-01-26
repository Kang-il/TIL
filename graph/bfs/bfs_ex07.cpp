#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;
// 퍼즐에 서 위치
struct POINT {
    int idx;
    int count;
    POINT(int idx,int count) : idx(idx),count(count){}
};
vector<int> ladders[MAX];
vector<int> snakes[MAX];
bool visited[101];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //(16928)
    // 뱀과 사다리 게임
    // 뱀과 사다리 게임을 즐겨 하는 큐브 러버는 어느날 궁금한 점이 생겼다.
    // 주사위를 조작해 내가 원하는 수가 나오게 된다면, 최소 몇 번만에 도착점에 도착할 수 있을까?
    // 게임은 정육면체 주사위를 사용하며, 주사위의 각 면에는 1부터 6까지 수가 하나씩 적혀있다. 
    // 게임은 크기가 10×10이고, 총 100개의 칸으로 나누어져 있는 보드판에서 진행된다. 
    // 보드판에는 1부터 100까지 수가 하나씩 순서대로 적혀져 있다.
    // 플레이어는 주사위를 굴려 나온 수만큼 이동해야 한다. 
    // 예를 들어, 플레이어가 i번 칸에 있고, 주사위를 굴려 나온 수가 4라면, i+4번 칸으로 이동해야 한다. 
    // 만약 주사위를 굴린 결과가 100번 칸을 넘어간다면 이동할 수 없다. 
    // 도착한 칸이 사다리면, 사다리를 타고 위로 올라간다. 뱀이 있는 칸에 도착하면, 뱀을 따라서 내려가게 된다. 
    // 즉, 사다리를 이용해 이동한 칸의 번호는 원래 있던 칸의 번호보다 크고, 
    // 뱀을 이용해 이동한 칸의 번호는 원래 있던 칸의 번호보다 작아진다.
    // 게임의 목표는 1번 칸에서 시작해서 100번 칸에 도착하는 것이다.
    // 게임판의 상태가 주어졌을 때, 100번 칸에 도착하기 위해 주사위를 굴려야 하는 횟수의 최솟값을 구해보자.
    // 첫째 줄에 게임판에 있는 사다리 수 :: N (1<=N<=15) 가 주어진다.
    // 뱀의 수 :: M (1<=M<=15)
    int N,M;
    cin>>N>>M;
    //사다리 입력
    for(int i=0;i<N;i++){
        int from,go;
        cin>>from>>go;
        ladders[from].push_back(go);
    }
    //뱀 입력
    for(int i=N;i<N+M;i++){
        int from,go;
        cin>>from>>go;
        snakes[from].push_back(go);
    }
    queue<POINT> q;
    //최초 위치는 1번 칸
    q.push(POINT(1,0));
    int ans=-1;
    while(!q.empty()){
        POINT pt=q.front();
        q.pop();
        //idx가 100이라면 도착
        if(pt.idx==100){
            //이전 도착 count보다 작은 횟수로 도착했다면 값을 바꿔줌
            if(ans==-1 || ans>pt.count) ans=pt.count;
        }
        //주사위 1 - 6 칸만큼 이동
        //이동 방식 -- 현 위치 + 주사위 나온 수  
        for(int i=1;i<=6;i++){
            //다음으로 이동 할 포인트 도출
            int nidx=pt.idx+i;
            //다음 이동 위치가 100이 넘는다면 continue
            if(nidx>100) continue;
            //이미 방문한 이력이 있다면 continue;
            // -- 최소값 찾는 문제에서는 이전에 방문한 곳은 다시 들리지 않는다.
            if(visited[nidx]) continue;
            // 현 위치 방문 체크
            visited[nidx]=true;
            // --- 다음 이동할 위치에 사다리 // 뱀 존재여부
            // - 한 위치당 최대 하나의 사다리 또는 뱀을 가지고 있으며
            // 동시에 두 가지 모두를 가지는 경우는 없다.
            if(ladders[nidx].size()>0){
                if(!visited[ladders[nidx][0]]){
                    q.push(POINT(ladders[nidx][0],pt.count+1));
                    visited[ladders[nidx][0]]=true;
                }
            }
            if(snakes[nidx].size()>0){
                if(!visited[snakes[nidx][0]]){
                    q.push(POINT(snakes[nidx][0],pt.count+1));
                    visited[snakes[nidx][0]]=true;
                    }
            }
            //사다리나 뱀이 없는 경우는 그 위치에서 push 한다.
            if(ladders[nidx].size()==0 && snakes[nidx].size()==0){
                q.push(POINT(nidx,pt.count+1));
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}