#include <iostream>

int D[1001];

int tiling(int N){
    if(N==1) return 1;
    if(N==2) return 3;

    if(D[N]>0) return D[N];
    //2x2가 추가되어 N-2의 방법이 두배로
    D[N]=(tiling(N-1)+tiling(N-2)*2)%10007;

    return D[N];
}
int main(){
    //(11727)
    /*
        2xn직사각형을 1x2 , 2x1 , 2x2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오
        홈페이지 예시참조 :: https://www.acmicpc.net/problem/11727
        첫째 줄에 2xn 크기의 직사각형을 채우는 방법의 수를 10007로 나눈 나머지를 출력한다.
    */
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    std::cin>>n;

    std::cout<<tiling(n)<<'\n';

    return 0;
}