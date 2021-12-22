#include <iostream>

int cnt[10];
// 수, 선택 수의 개수
void go(int idx, int selected, int N, int M){
    if(selected=M){
        for(int i=1; i<=N ; i++){
            for(int j=1;j<=cnt[i];j++){
                std::cout<<i<<' ';
            }
        }
        std::cout<<'\n';
        return;
    }
    if(idx>N) return;

    //선택하는 부분
    // 몇 개를 선택해야 할 지 결정해야 하는데
    // M개를 선택 
    // M-select 개부터 1개 까지 반복한다.
    // cnt[idx]=몇개를 선택했는지 항상 넣어주며
    for(int i=M-selected ; i>=1 ; i--){
        cnt[idx]=i;
        go(idx+1,selected+1,N,M);
    }
    //선택하지 않는 부분
    cnt[idx]=0;
    go(idx+1,selected,N,M);
}
int main(){
    //(15652)
    // N과 M(4)
    // 자연수 N과 M이 주어졌을 때 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 
    // 프로그램을 작성하시오.
    // 1. 1부터 N까지 자연수 중에서 M개를 고른 수열
    // 2. 같은 수를 여러 번 골라도 된다.
    // 3. 고른 수열은 비내림차순이어야 한다.
    // 길이가 K인 수열 A가 A1<=A2<=....<=Ak-1<=Ak 를 만족하면 비내림차순이라고 한다.
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int N,M;
    std::cin>>N>>M;
    
    return 0;
}