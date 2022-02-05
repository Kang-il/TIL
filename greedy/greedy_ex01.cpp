#include <iostream>
using namespace std;
int N,K;
int wallet[10];
void solution(){
    int coin=0;
    for(int i=0;i<N;i++){
        // K의 값보다 선택한 동전의 가치가 작거나 같을경우
        if(wallet[i]<=K){
            // ㅏ
            coin+=K/wallet[i];
            total=K%wallet[i];
        }
        if(total==0) break;
    }
    cout<<coin<<'\n';
}
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>K;
    // 동전의 크기는 오름차순으로 입력이 됨.
    // solution에서 편하게 하기위해 내림차순으로 입력을 받아주었다.
    for(int i=N-1;i>=0;i--){
        cin>>wallet[i];
    }
}
int main(){
    //(11047)
    // 동전 0
    // 준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.
    // 동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 
    // 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.
    // 첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)

    // 둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. 
    // (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)
    
    // 입력
    input();
    solution();
    return 0;
}