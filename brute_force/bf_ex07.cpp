#include <iostream>

int main(){
    //(1748)
    // 수 이어쓰기 1
    // 1부터 N까지의 수를 이어서 쓰면 다음과 같이 새로운 하나의 수를 얻을 수 있다.
    // 12345678910111213....
    // 이렇게 만들어진 새로운 수는 몇 자리 수 일까?
    // 이 수의 자릿수를 구하시오 
    // 1<=N<=100,000,000
    

    // (9-1+1)*2 -- 1자리 수의 갯수
    // (99-10+1)*2 -- 2자리 수의 갯수
    // (999-100+1)*2 -- 3자리 수의 갯수
    // ...
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin>>N;
    long long ans=0;
    for(int start=1,len=1;start<=N;start*=10,len++){
        int end=start*10-1;
        if(end>N){
            end=N;
        }
        ans=(long long)(end-start+1)*len;
    }
    std::cout<<ans<<'\n';
    return 0;
}