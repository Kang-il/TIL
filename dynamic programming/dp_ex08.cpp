#include <iostream>


long long D[10][10];
const long long mod=1000000000LL;
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    //쉬운 계단 수
    // 인접한 자리의 차이가 1이 나는 수를 계단 수 라고 한다.
    // ex > 45656
    // 길이가 N인 계단수의 개수를 구하는 문제

    //첫 째 줄에 N이 주어진다 N은 1보다 크고 100보다 작거나 같은 자연수이다.

    //D[N][L] -- >길이가 N인 계단수 의 마지막 수  L
    // L-1 , L+1
    // D[N-1][L-1]
    // +
    // D[N-1][L+1]
    // 항상 가능 한 것은 아니다.
    // L이 0인 경우 L-1은 불가능하다.
    // L이 9 인 경우 10은 불가능하다

    int N;
    std::cin>>N;

    //길이가 1인 계단 수 1-9
    for(int i=1;i<=9;i++) D[1][i]=1;
    for(int i=2; i<= N ; i++){
        for(int j=0; j<=9;j++){
            D[i][j]=0;
            if(j-1>0) D[i][j] += D[i-1][j-1];
            if(j+1<=9) D[i][j] += D[i-1][j+1];
            D[i][j]%= mod;
        }
    }

    long long ans=0;
    for(int i=0; i<=9;i++) ans+=D[N][i];

    std::cout<< ans%mod <<'\n';

    return 0;

    //문제풀이 1. 자릿수의 갯수를 저장할 2차원 배열을 선언
    //D[a][b] = 길이가 a일 때 마지막 수가 b일 경우의 계단의 수를 의미한다.
    //D[1][x] 의 경우 x에 어떤 값이 오더라도 1이 될 것이다.
}