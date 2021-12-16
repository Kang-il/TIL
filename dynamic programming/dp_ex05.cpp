
#include <iostream>
#include <vector>

int D[1001];
int P[1001];

int main(){
    //(11052)
    //카드 N개를 구매해야 한다.
    //카드팩은 N가지 종류가 존재.
    //i번째 카드팩은 i개의 카드를 담고 있고, 가격은 P[i] 원이다.
    //카드 N개를 구매하는 비용의 최대값을 구하는 문제

    //첫째 줄에 민규가 구매하려는 카드의 개수 
    //둘 째줄에 Pi가 P1부터 Pn까지 순서대로 주어진다.


    //카드팩에 들어있는 합을 구하니 N개가 됐다는 것.
    // 마지막 카드팩에 카드가 몇 개? -- 알 수 없다.
    // 알수없다? 다 해보면 된다.

    //D[N] 비용의 최대값
    //D[N-i] 개
    //P[i] -- 카드팩
    //D[N] = max (D[N-i]+p[i])
    //1<=i<=N
    int N;
    std::cin>>N; 

    for(int i=1;i<=N;i++){
        std::cin>>P[i];
    }
    //최대값 구하기
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            D[i]=std::max(D[i],D[i-j]+P[j]);
        }
    }

    std::cout<<D[N];


    return 0;
}
