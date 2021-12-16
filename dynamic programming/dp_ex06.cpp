#include <iostream>

int D[1001];
int P[1001];
int main(){
    //(16194) -- 카드 구매하기 2
    // 카드는 카드팩 형태로만 구매할 수 있고, 1개가 포함딘 카드팩, 2개가 포함된 카드팩
    // ...N개가 포함된 카드팩과 같이 총 N가지가 존재한다.
    // 최소로 지불해서 카드 N개를 구매하려한다.
    // 첫쩨 줄에 민규가 구매하려고 하는 카드의 갯수 N개가 주어진다.(1<=N<=1,000)
    // 둘째 줄에는 Pi가 P1에서부터 ~ Pn까지 순서대로 주어진다. (1<=Pi<=10,000)
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin>>N;

    for(int i=1;i<=N;i++){
        //카드의 최대 가격은 1000*10000을 넘지 않으므로 모두 초기화
        D[i]=1000*10000;
        int tmp;
        std::cin>>tmp;
        P[i]=tmp;
    }

    D[0]=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            D[i]=std::min(D[i],D[i-j]+P[j]);
        }
    }

    std::cout<<D[N]<<'\n';

    return 0;
}