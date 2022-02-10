#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct jewel{
    //무게 가격 w==0 보석 : w==1 가방
    int m,v,w;
};
int N,K;
vector<jewel> jVec;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>K;
    jVec.resize(N+K);
    for(int i=0;i<N;i++){
        cin>>jVec[i].m>>jVec[i].v;
    }
    for(int i=0 ; i<K ; i++){
        cin>>jVec[i+N].m;
        jVec[i+N].w=1;
    }
}
void solution(){
    sort(jVec.begin(),jVec.end(),[&](jewel &u, jewel &v){
        return u.m < v.m || ( u.m == v.m && u.w < v.w);
    });
    priority_queue<int> q;
    long long ans=0;
    for(jewel &j : jVec){
        if(j.w==0){
            q.push(j.v);
        }else {
            if(!q.empty()){
                ans+=(long long)q.top();
                q.pop();
            }
        }
    }
    cout<<ans<<'\n';
}
int main(){
    // (1202)
    // 보석 도둑 - priority queue 사용
    // 세계적인 도둑 상덕이는 보석점을 털기로 결심했다.
    // 상덕이가 털 보석점에는 보석이 총 N개 있다. 
    // 각 보석은 무게 Mi와 가격 Vi를 가지고 있다. 
    // 상덕이는 가방을 K개 가지고 있고, 각 가방에 담을 수 있는 최대 무게는 Ci이다. 
    // 가방에는 최대 한 개의 보석만 넣을 수 있다.
    // 상덕이가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오.
    // 첫째 줄에 N과 K가 주어진다. (1 ≤ N, K ≤ 300,000)

    // 다음 N개 줄에는 각 보석의 정보 Mi와 Vi가 주어진다. (0 ≤ Mi, Vi ≤ 1,000,000)
    // 다음 K개 줄에는 가방에 담을 수 있는 최대 무게 Ci가 주어진다. (1 ≤ Ci ≤ 100,000,000)
    // 모든 숫자는 양의 정수이다.
    
    // 첫째 줄에 상덕이가 훔칠 수 있는 보석 가격의 합의 최댓값을 출력한다.
    input();
    solution();
    return 0;
}