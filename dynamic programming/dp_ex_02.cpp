#include <iostream>

int dp[1001];
int go(int n){
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
        dp[i]%=10007;
    }
    return dp[n];
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int N=0;
    std::cin>>N;

    dp[1]=1;
    dp[2]=2;
    int ans=go(N);

    std::cout<<ans<<'\n';
    return 0;
}