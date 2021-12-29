#include <iostream>

int nums[20];
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // (1182)
    // 부분수열의 합
    // N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이
    // S가 되는 경우의 수를 구하는 프로그램을 작성하시오
    // 1<=N<=20
    // |S| <= 1,000,000

    int N;
    int S;
    std::cin>>N;
    std::cin>>S;
    for(int i=0;i<N;i++){
        std::cin>>nums[i];
    }
    int ans=0;
    for(int i=1;i<(1<<N);i++){
        int sum=0;
        for(int k=0;k<N;k++){
            if(i&(1<<k)){
                sum+=nums[k];
            }
        }
    }
    std::cout<<ans<<'\n';
    return 0;
}