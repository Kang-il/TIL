#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct BRIDGE{
    // 어디로 향하는지
    int to;
    // 다리가 견딜 수 있는 무게
    int weight;
    BRIDGE(int to, int weight):to(to),weight(weight){}
};

int N,M;
pair<int,int> factory;
vector<vector<BRIDGE>> bridges;
bool visited[100001];

int heavyest;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    bridges.resize(N+1);
    while(M--){
        int from, to;
        int weight;
        cin>>from>>to>>weight;
        // 무게중 가장 큰 것 기록
        if(heavyest<weight)heavyest=weight;
        // 양방향 다리.
        bridges[from].push_back(BRIDGE(to,weight));
        bridges[to].push_back(BRIDGE(from,weight));
    }

    //두 공장 마킹
    cin>>factory.first>>factory.second;
}

bool dfs(int idx, int weight){
    // 이미 방문 한 경우 false 반환
    if(visited[idx]) return false;
    // 방문 기록
    visited[idx]=true;
    // 해당 위치가 방문하려고 한 목적지라면 true 반환
    if(idx==factory.second) return true;
    // dfs탐색
    for(BRIDGE &cur : bridges[idx]){
        // 해당 다리가 현재 무게를 견딜 수 있을 경우에만 dfs 탐색
        if(cur.weight>=weight){
            if(dfs(cur.to,weight)){
                return true;
            }
        }
    }
    //여기까지 도달했는데 함수를 빠져나가지 못했다면 false 반환
    return false;
}
void solution(){
    //이분탐색
    int left,right;
    left=1;
    right=heavyest;
    int ans=0;
    while(left<=right){
        int mid=(left+right)/2;
        memset(visited,false,sizeof(visited));
        if(dfs(factory.first,mid)){
            ans=mid;
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    cout<<ans<<'\n';
}
int main(){
    // (1939)
    // 중량제한
    // N(2 ≤ N ≤ 10,000)개의 섬으로 이루어진 나라가 있다. 
    // 이들 중 몇 개의 섬 사이에는 다리가 설치되어 있어서 차들이 다닐 수 있다.
    // 영식 중공업에서는 두 개의 섬에 공장을 세워 두고 물품을 생산하는 일을 하고 있다. 
    // 물품을 생산하다 보면 공장에서 다른 공장으로 생산 중이던 물품을 수송해야 할 일이 생기곤 한다. 
    // 그런데 각각의 다리마다 중량제한이 있기 때문에 무턱대고 물품을 옮길 순 없다.
    // 만약 중량제한을 초과하는 양의 물품이 다리를 지나게 되면 다리가 무너지게 된다.
    // 한 번의 이동에서 옮길 수 있는 물품들의 중량의 최댓값을 구하는 프로그램을 작성하시오.

    // 첫째 줄에 N, M(1 ≤ M ≤ 100,000)이 주어진다.
    // 다음 M개의 줄에는 다리에 대한 정보를 나타내는 세 정수 A, B(1 ≤ A, B ≤ N), C(1 ≤ C ≤ 1,000,000,000)가 주어진다.
    // 이는 A번 섬과 B번 섬 사이에 중량제한이 C인 다리가 존재한다는 의미이다.
    // 서로 같은 두 섬 사이에 여러 개의 다리가 있을 수도 있으며, 모든 다리는 양방향이다.
    // 마지막 줄에는 공장이 위치해 있는 섬의 번호를 나타내는 서로 다른 두 정수가 주어진다.
    // 공장이 있는 두 섬을 연결하는 경로는 항상 존재하는 데이터만 입력으로 주어진다.
    input();
    solution();
    return 0;
}