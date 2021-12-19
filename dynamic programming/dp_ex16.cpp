#include<iostream>

int D[1001][3];

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    //(1149)
    //RGB거리
    //RGB거리에 사는 사람들은 집을 빨강 초록 파랑 중에 하나로 칠하려고 한다.
    //또한 그들은 모든 이웃은 같은 색으로 칠할 수 없다는 규칙을 정했다.
    // 집 i의 이웃은 집 i-1과 집 i+1이고, 첫 집과 마지막 집은 이웃이 아니다.
    // 각 집을 빨강으로 칠할 때 드는 비용, 초록으로 칠할 때 드는 비용, 파랑으로 드는 비용이 주어질 때
    // 모든 집을 칠하는 최솟값을 구하는 문데

    // 첫 째줄에 집의수 (2<= N <= 1000)
    // 둘째 줄부터 N개의 줄에는 각집을 빨강 초록 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다.
    // 집을 칠하는 비용은 1000보다 작거나 같은 자연수이다.

    int N;
    std::cin>>N;
    D[0][0]=0;
    D[0][1]=0;
    D[0][2]=0;
    int cost[3];
    for(int i=1;i<=N;i++){
        std::cin>>cost[0]>>cost[1]>>cost[2];
        D[i][0]=std::min(D[i-1][1],D[i-1][2])+cost[0];
        D[i][1]=std::min(D[i-1][0],D[i-1][2])+cost[1];
        D[i][2]=std::min(D[i-1][0],D[i-1][1])+cost[2];
    }
    std::cout<<std::min(D[N][0],std::min(D[N][1],D[N][2]))<<'\n';
    return 0;
}