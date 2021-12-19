#include <iostream>

int d[100001];
int go(int n){
    for(int i=1;i<=n;i++){
        //쵀대값으로 초기화 
        // 1^2 + 1^2 + 1^2 .... + 1^2로 했을 때 N의 항의 갯수는 N개를 최대값으로 가질 수 있다.
        d[i]=i;
        //j^2은 i를 넘을 수 없다.
        for(int j=1; j*j<=i;j++){
            if(d[i]>d[i-j*j]+1){
                d[i]=d[i-j*j]+1;
            }
        }
    }
    return d[n];
}
int main(){
    //1699
    //제곱수의 합
    //어떤 자연수 N은 그보다 작거나 같은 제곱수들의 합으로 나타낼 수 있다.
    //ex 11=3^2+1^2+1^2(3개 항) 
    //이런 표현방법은 여러가지가 될 수 있음
    //ex> 11=2^2+2^2+1^2+1^2 (5개 항)
    //최소항으로 표현 했을 때 항의 갯수를 출력하시오
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin>>n;
    std::cout<<go(n)<<'\n';

    return 0;
}