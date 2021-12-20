#include <iostream>

int D[100001];
int S[100001];
const int MOD=9901;
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    //(1309)
    // 동물원(새로운 방식)
    // 2차원 다이나믹
    // 단 i번째 무조건 동물이 있어야 한다.
    // i이전 동물이 있는 줄은 어디일까? (알 수 없다)
    // i-1 , i-2 .... 모른다.
    // D[i-1]+2*D[i-2]+2*D[2]+2*D[1]
    // i -> i-1 D[i]
    // i -> i-2 2*D[i-1]

    int N;
    std::cin>>N;

    D[0]=S[0]=1;
    D[1]=2;
    S[1]=D[0]+D[1];
    for(int i=2;i<=N;i++){
        D[i]=D[i-1]+2*S[i-2];
        S[i]=S[i-1]+D[i];
        D[i]%=MOD;
        S[i]%=MOD;
    }

    std::cout<<S[N]<<'\n';
    return 0;
}