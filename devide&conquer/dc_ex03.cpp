#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector<int> A;
vector<int> B;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        A.push_back(tmp);
    }
    for(int i=0;i<M;i++){
        int tmp;
        cin>>tmp;
        B.push_back(tmp);
    }
}
void solution(){
    int a_idx=0;
    int b_idx=0;
    while(a_idx < N && b_idx < M){
        if(A[a_idx]<=B[b_idx]){
            cout<< A[a_idx++] << ' ';
        }else {
            cout<< B[b_idx++] << ' ';
        }
    }
    while(a_idx < N){
        cout<< A[a_idx++] << ' ';
    }
    while(b_idx < M){
        cout<< B[b_idx++] << ' ';
    }
}
int main(){
    // (11728)
    // 배열 합치기
    // 정렬되어있는 두 배열 A와 B가 주어진다. 두 배열을 합친 다음 정렬해서 출력하는 프로그램을 작성하시오.

    // 첫째 줄에 배열 A의 크기 N, 배열 B의 크기 M이 주어진다. (1 ≤ N, M ≤ 1,000,000)
    // 둘째 줄에는 배열 A의 내용이, 셋째 줄에는 배열 B의 내용이 주어진다. 
    // 배열에 들어있는 수는 절댓값이 109보다 작거나 같은 정수이다.
    
    // 첫째 줄에 두 배열을 합친 후 정렬한 결과를 출력한다.
    input();
    solution();
    return 0;
}