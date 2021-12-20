#include <iostream>

int A[502][502];
int D[502][502];

int main(){
    //(1932)
    //정수 삼각형
    //              7
    //            3    8
    //          8   1    0
    //        2   7    4   4
    //      4   5    2   6   5
    // 위 그림은 크기가 5 인 정수 삼각형의 한 모습이다
    // 맨 위층 7 부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때
    // 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라.
    // 아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에만
    // 선택할 수 있다. 삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0이상 9999이하이다.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int N;
    std::cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            std::cin>>A[i][j];
        }
    }
    D[1][1]=A[1][1];

    for(int i=2;i<=N;i++){
        for(int j=1;j<=i;j++){
            D[i][j]=std::max(D[i-1][j-1],D[i-1][j])+A[i][j];
        }
    }
    int max=0;
    for(int i=1;i<=N;i++){
        if(max < D[N][i]) max=D[N][i];
    }
    std::cout<<max<<'\n';
    return 0;
}