#include <iostream>

const int MAX=201;
const long long MOD = 1000000000LL;
long long D[MAX][MAX];

int main(){
    //(2225)
    // 합분해
    // 0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하시요
    // 2+1 과 1+2는 서로 다른 경우
    // 또한 한 개의 수를 여러 번 쓸 수 있다.
    // 1 <= N,K <= 200
    // 첫째 줄에 답을 1,000,000,000으로 나눈 나머지를 출력한다.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N,K;
    std::cin>>N>>K;

    D[0][0]=1LL;
    for(int i=1 ; i<=K ; i++){
        for(int j=0 ; j<=N ; j++){
            for(int l=0 ; l<=j ; l++){
                D[i][j]+=D[i-1][j-l];
                D[i][j]%=MOD;
            }
        }
    }

    std::cout<<D[K][N]<<'\n';

    return 0;
}