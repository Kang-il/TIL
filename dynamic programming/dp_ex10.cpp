#include <iostream>

int arr[1001];
int D[1001];
int sum=1;
int main(){
    //(11053)
    //가장 긴 증가하는 부분수열
    //LIS (Longest Increasing Subsequence)
    //수열 A가 주어졌을 때, 가장 긴 증가하는 부분수열을 구하는 문제
    // A=[10,20,10,30,20,50]
    // 10,20,30,50 이 된다

    //LIS -- 증가하는 부분수열중 가장 긴 것
    // 순서를 유지하면서 띄엄띄엄
    // 10 -- 1
    // D[i] -- 1

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin>>N;
    for(int i=1 ; i<=N ; i++){
        int tmp;
        std::cin>>tmp;
        arr[i]=tmp;
        D[i]=1;
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<i;j++){
            if(arr[i]>arr[j]){
                D[i]=std::max(D[i],D[j]+1);
            }
        }
        sum=std::max(sum,D[i]);
    }

    std::cout<<sum<<'\n';

    return 0;
}