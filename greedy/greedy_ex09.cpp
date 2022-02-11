#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10001
using namespace std;
int N;
vector<int> lec[MAX];
int max_day=0;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    for(int i=0;i<N;i++){
        int p, d;
        cin>>p>>d;
        lec[d].push_back(p);
        max_day=max(max_day,d);
    }
}
void solution(){
    priority_queue<int> pq;
    int ans=0;
    for(int i=max_day ; i>0 ; i--){
        for(int k : lec[i]) pq.push(k);
        if(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
    }
    cout<<ans<<'\n';
}
int main(){
    // (2109)
    // 순회 강연
    // 한 저명한 학자에게 n(0 ≤ n ≤ 10,000)개의 대학에서 강연 요청을 해 왔다.
    // 각 대학에서는 d(1 ≤ d ≤ 10,000)일 안에 와서 강연을 해 주면 
    // p(1 ≤ p ≤ 10,000)만큼의 강연료를 지불하겠다고 알려왔다. 
    // 각 대학에서 제시하는 d와 p값은 서로 다를 수도 있다. 
    // 이 학자는 이를 바탕으로, 가장 많은 돈을 벌 수 있도록 순회강연을 하려 한다. 
    // 연의 특성상, 이 학자는 하루에 최대 한 곳에서만 강연을 할 수 있다.

    // 예를 들어 네 대학에서 제시한 p값이 각각 50, 10, 20, 30이고, d값이 차례로 2, 1, 2, 1 이라고 하자. 
    // 이럴 때에는 첫째 날에 4번 대학에서 강연을 하고, 둘째 날에 1번 대학에서 강연을 하면 80만큼의 돈을 벌 수 있다.
    // 첫째 줄에 정수 n이 주어진다. 다음 n개의 줄에는 각 대학에서 제시한 p값과 d값이 주어진다.
    // 첫째 줄에 최대로 벌 수 있는 돈을 출력한다.
    input();
    solution();
    return 0;
}