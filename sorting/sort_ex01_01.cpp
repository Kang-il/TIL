#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> A;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    A.resize(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    } 
}
void solution(){
    sort(A.begin(),A.end());
    for(int i=0;i<N;i++){
        cout<<A[i]<<'\n';
    }
}
int main(){
    // (2751)
    // 수 정렬하기 2 -- 기본 제공 라이브러리 사용
    // N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
    // 첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다.
    // 둘째 줄부터 N개의 줄에는 수가 주어진다. 
    // 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

    // 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
    input();
    solution();
    return 0;
}