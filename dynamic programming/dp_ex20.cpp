#include <iostream>
#include <algorithm>

int wines[10001];
int D[10001];
int main(){
    //(2156)
    // 포도주 시식
    // 포도주가 일렬로 놓여있고, 다음과 같은 2가지 규칙을 지키면서 포도주를 최대한 많이 마시려고 한다.
    // 1. 포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야하고, 마신 후에는 원래위치에 다시 놓아야 한다.
    // 2. 연속으로 놓여있는 3잔을 모두 마실 수는 없다.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin>>N;

    //wines[N]=N번 째 포도주의 양
    //D[N]=N번째 까지 마신 포도주의 최대 양
    for(int i=1;i<=N;i++){
        int tmp;
        std::cin>>tmp;
        wines[i]=tmp;
    }

    //초기값 설정
    D[0]=wines[0]=0;
    //첫 번째 순서의 최대값은 첫 번째 와인을 마시는 경우
    D[1]=wines[1];
    //두 번째 순서의 최대값은 첫 번째, 두 번째 아인을 모두 마시는 경우
    D[2]=D[1]+wines[2];
    //세 번째 와인 부터는 연속 세잔 시식 불가능 이므로 값을 비교한다
    for(int i=3;i<=N;i++){
        //현재의 값 :: 현재 와인을 먹지 않은 최대값
        D[i]=D[i-1];

        if(D[i]<D[i-2]+wines[i]){
            D[i]=D[i-2]+wines[i];
        }
        if(D[i]<D[i-3]+wines[i-1]+wines[i]){
            D[i]=D[i-3]+wines[i-1]+wines[i];
        }
    }

    std::cout<<D[N]<<'\n';

    return 0;
}