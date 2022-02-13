#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,K;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>K;
    return;
}
void solution(){
    for(int a=0;a<=N;a++){
        int b=N-a;
        if(a*b < K) continue;
        vector<int> cnt(b+1);
        for(int i=0;i<a;i++){
            int x=min(b,K);
            cnt[x]+=1;
            K-=x;
        }
        for(int i=b;i>=0;i--){
            for(int j=0;j<cnt[i];j++){
                cout<<'A';
            }
            if(i>0){
                cout<<'B';
            }
        }
        cout<<'\n';
        return;
    }
    cout<<-1<<'\n';
    return;
}
int main(){
    // (12970)
    // AB
    // 정수 N과 K가 주어졌을 때, 다음 두 조건을 만족하는 문자열 S를 찾는 프로그램을 작성하시오.

    // 문자열 S의 길이는 N이고, 'A', 'B'로 이루어져 있다.
    // 문자열 S에는 0 ≤ i < j < N 이면서 
    // s[i] == 'A' && s[j] == 'B'를 만족하는 (i, j) 쌍이 K개가 있다.

    // 첫째 줄에 N과 K가 주어진다. (2 ≤ N ≤ 50, 0 ≤ K ≤ N(N-1)/2)
    // 첫째 줄에 문제의 조건을 만족하는 문자열 S를 출력한다. 
    // 가능한 S가 여러 가지라면, 아무거나 출력한다. 
    // 만약, 그러한 S가 존재하지 않는 경우에는 -1을 출력한다.
    input();
    solution();
    return 0;
}