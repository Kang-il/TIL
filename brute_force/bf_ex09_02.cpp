#include <iostream>

int A[10];

// idx -- 선택하고자 하는 수의 후보
// selected -- 방의 인덱스
// N 1-N 까지의 범위
// M 수열의 길이
void go(int idx, int selected, int N, int M){
    //선택된 수가 M개라면 출력(수열이 완성됨).
    if(selected==M){
        for(int i=0;i<M;i++){
            std::cout<<A[i];
            if(i!=M-1) std::cout<<" ";
        }
        std::cout<<'\n';
        return;
    }
    //idx 가 N을 넘어선다면 범위를 벗어나므로 함수 종료
    if(idx>N) return;

    //1-N 의 수들로 수열을 만들 때 :: 
    // 해당 수가 선택된다 / 해당 수가 선택되지 않는다.
    // 의 두 가지의 상태를 띈다.
    A[selected]=idx;
    go(idx+1,selected+1,N,M);
    A[selected]=0;
    go(idx+1,selected,N,M);
}

int main(){
    //(15650)
    // N과 M(2)
    // 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는
    // 프로그램을 작성하시오
    // 1. 1 부터 N 까지 자연수 중에서 중복없이 M개를 고른 수열
    // 2. 고른 수열은 오름차순 이어야 한다.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N,M;
    std::cin>>N>>M;

    go(1,0,N,M);

    return 0;
}