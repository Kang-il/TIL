#include <iostream>


long long D[1000001];
const long long MOD = 1000000009LL;

int main(){
    //15988
    // 1,2,3 더하기 3
    // 정수 4를 1,2,3의 합으로 나타내는 방법은 총 7가지가 있다.
    // 합을 나타낼 때는 수를 1개 이상 사용해야 한다.
    // 1+1+1+1
    // 1+1+2
    // 1+2+1
    // 2+1+1
    // 2+2
    // 1+3
    // 3+1
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin>>T;
    D[0]=1;

    for(int i=1 ; i<=1000000 ; i++){
        if(i-1>=0) D[i]+=D[i-1];
        if(i-2>=0) D[i]+=D[i-2];
        if(i-3>=0) D[i]+=D[i-3];
        D[i]%=MOD;
    }

    while(T--){
        int N;
        std::cin>>N;
        std::cout<<D[N]<<'\n';
    }


    return 0;
}