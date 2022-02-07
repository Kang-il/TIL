#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
void change(vector<int> &start, int idx){
    for(int i=idx-1;i<=idx+1;i++){
        if(i>=0 && i<N){
            start[i]=1-start[i];
        }
    }
}
pair<int,int> go(vector<int> start,vector<int> &goal){
    int ans=0;
    for(int i=0;i<N-1;i++){
        if(start[i]!=goal[i]){
            change(start,i+1);
            ans+=1;
        }
    }
    if(start==goal) return make_pair(true,ans);
    else return make_pair(false,ans);
}
void solution(vector<int> &start, vector<int> &goal){
    auto p1=go(start,goal);
    change(start,0);
    auto p2=go(start,goal);
    if(p2.first){
        p2.second++;
    }
    if(p1.first && p2.first) cout<<min(p1.second, p2.second)<<'\n';
    else if(p1.first) cout<<p1.second<<'\n';
    else if(p2.first) cout<<p2.second<<'\n';
    else cout<<-1<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // (2138)
    // 전구와 스위치
    // N개의 스위치와 N개의 전구가 있다. 
    // 각각의 전구는 켜져 있는 상태와 꺼져 있는 상태 중 하나의 상태를 가진다. 
    // i(1 < i < N)번 스위치를 누르면 i-1, i, i+1의 세 개의 전구의 상태가 바뀐다. 
    // 즉, 꺼져 있는 전구는 켜지고, 켜져 있는 전구는 꺼지게 된다. 
    // 1번 스위치를 눌렀을 경우에는 1, 2번 전구의 상태가 바뀌고, N번 스위치를 눌렀을 경우에는 N-1, N번 전구의 상태가 바뀐다.

    // N개의 전구들의 현재 상태와 우리가 만들고자 하는 상태가 주어졌을 때, 
    // 그 상태를 만들기 위해 스위치를 최소 몇 번 누르면 되는지 알아내는 프로그램을 작성하시오.

    // 첫째 줄에 자연수 N(2 ≤ N ≤ 100,000)이 주어진다. 
    // 다음 줄에는 전구들의 현재 상태를 나타내는 숫자 N개가 공백 없이 주어진다. 
    // 그 다음 줄에는 우리가 만들고자 하는 전구들의 상태를 나타내는 숫자 N개가 공백 없이 주어진다. 
    // 0은 켜져 있는 상태, 1은 꺼져 있는 상태를 의미한다.
    cin>>N;
    vector<int> start(N);
    vector<int> goal(N);
    string tmp;
    cin>>tmp;
    for(int i=0;i<N;i++){
        start[i]=tmp[i]-'0';
    }
    cin>>tmp;
    for(int i=0;i<N;i++){
        goal[i]=tmp[i]-'0';
    }
    solution(start,goal);
    return 0;
}