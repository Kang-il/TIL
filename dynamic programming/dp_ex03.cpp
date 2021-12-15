#include <iostream>

int dp[1001];

int go(int n){

   if(n==1) return 1;
   if(n==2) return 2;
   if(dp[n]>0) return dp[n];

   dp[n]=go(n-1)+go(n-2);
   dp[n]%=10007;

   return dp[n];
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //11726
    //2xn 타일링
    //-- 2xn 직사각형을 1x2 , 2x1 타일로 채우는 방법의 수
    //D[n] = 2xn 직사각형을 채우는 방법의 수
    int N=0;
    std::cin>>N;

    int num=go(N);

    std::cout<<num<<'\n';

    return 0;
}