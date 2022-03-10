#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;


int N;
long long card[MAX]{0,};
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>card[i];
    }
}
void solution(){
    sort(card,card+N);
    long long ans = card[0];
    int cnt=1;
    int max=1;
    for(int i=1;i<N;i++){
        if(card[i] == card[i-1]){
            cnt++;
        }else cnt=1;

        if(max<cnt){
            max=cnt;
            ans=card[i];
        }
    }
    cout<<ans<<'\n';
}
int main(){
    // (11652)
    // 카드
    // 준규는 숫자 카드 N장을 가지고 있다.
    // 숫자 카드에는 정수가 하나 적혀있는데, 적혀있는 수는 -2^62보다 크거나 같고, 2^62보다 작거나 같다.

    // 준규가 가지고 있는 카드가 주어졌을 때, 가장 많이 가지고 있는 정수를 구하는 프로그램을 작성하시오.
    // 만약, 가장 많이 가지고 있는 정수가 여러 가지라면, 작은 것을 출력한다.
    // 첫째 줄에 준규가 가지고 있는 숫자 카드의 개수 N (1 ≤ N ≤ 100,000)이 주어진다.
    // 둘째 줄부터 N개 줄에는 숫자 카드에 적혀있는 정수가 주어진다.

    // 첫째 줄에 준규가 가장 많이 가지고 있는 정수를 출력한다.
    input();
    solution();
    return 0;
}