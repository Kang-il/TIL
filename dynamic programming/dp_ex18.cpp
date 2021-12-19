#include <iostream>

int D[1001][10];
const int MOD=10007LL;
int main(){
    //(11057)
    //오르막 수
    // 오루막 수는 자리가 오름차순을 이루는 수를 말한다.
    // 이 때, 인접한 수가 같아도 오름차순으로 친다.
    // ex> 2234 1119 3678
    // 수의 길이 N이 주어졌을 때 오르막 수의 개수를 구하는 프로그램을 작성하시요.
    // 수는 0으로 시작할 수 있다.
    int N;

    std::cin>>N;

    for(int i=0;i<10;i++){
        D[1][i]=1;
    }

    for(int i=2 ; i<=N ; i++){
        for(int j=0 ; j<10 ; j++){
            for(int k=0 ; k<=j ; k++){
                D[i][j]+=D[i-1][k];
                D[i][j]%=MOD;
            }
        }
    }

    int ans=0;
    for(int i=0;i<10;i++){
        ans+=D[N][i];
    }
    

    std::cout<<ans%MOD<<'\n';
    return 0;
}