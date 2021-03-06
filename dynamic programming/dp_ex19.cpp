#include <iostream>
#include <algorithm>

long long D[100001][3];
long long cost[100001][2];

int main(){
    // (9465)
    // 스티커
    // 상근이의 여동생 상냥이는 문방구에서 스티커 2n 개를 구매 했다.
    // 스티커는 2행 n열로 배치되어있다.
    // 상냥이의 스티커의 품질이 매우 좋지않아 스티커 한 장을 떼면 그 스티커와 변을 공유하는 스티커는
    // 모두 찢어져서 사용할 수 없게 된다.
    // 즉, 뗀 쓰티커의 왼쪽, 오른쪽, 위, 아래에 있는 스티커는 사용할 수 없게된다.
    // 모든 스티커를 붙일 수 없게 된 상냥이는 각 스티커에 점수를 매기고, 점수의 합이 최대게 되게
    // 스티커를 떼어내려고 한다.
    // 스티커의 점수의 최댓값을 구하는 프로그램을 작성하ㅣㅅ오.
    // 즉 2n 개의 스티커 중에서 점수의 합이 최대가 되면서 서로 변을 공유하지 않는 스티커 집합을 구해야 한다.

    // 첫 째 줄에 테스트케이스의 개수 T가 주어진다.
    // 각 테스트 케이스의 첫째 줄에는 n(1<=n<=100,000)이 주어진다.
    // 다음 두 줄에는 n개의 정수가 주어지며, 각 정수는 그 위치에 해당하는 스티커의 점수이다.
    // 연속하는 두 정수 사이에는 빈칸이 하나 있다. 
    // 점수는 0보다 크거나 같고 100보다 작은 정수이다.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin>>T;
    while(T--){
        int a;
        std::cin>>a;
        for(int i=1;i<=a;i++) std::cin>>cost[i][0];
        for(int i=1;i<=a;i++) std::cin>>cost[i][1];
        
        D[0][0]=D[0][1]=D[0][2]=0;

        for(int i=1 ; i<=a ; i++){
            D[i][0] = std::max({D[i-1][0],D[i-1][1],D[i-1][2]});
            D[i][1] = std::max(D[i-1][0],D[i-1][2])+cost[i][0];
            D[i][2] = std::max(D[i-1][0],D[i-1][1])+cost[i][1];
        }
        std::cout<<max({D[a][0],D[a][1],D[a][2]})<<'\n';
    }
    return 0;
}