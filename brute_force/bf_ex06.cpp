#include <iostream>
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //(6064)
    // 카잉 달력
    // M,N 4만 16억 -- 16초
    // 건너뛰며 해보기
    
    //M=5
    //N=7
    //나머지 연산
    //모든 값에서 1을 빼면
    //나눈 나머지가 값을 의미한다.
    //(i%M ,i%N)
    int T;
    std::cin>>T;
    while(T--){
        int M,N,x,y;
        std::cin>>M>>N>>x>>y;
        x-=1;
        y-=1;
        bool ok=false;
        for(int k=x;k<(N*M);k+=M){
            if(k%N==y){
                std::cout<<k+1<<'\n';
                ok=true;
                break;
            }
        }
        if(!ok){
            std::cout<<-1<<'\n';
        }

    }
    return 0;
}