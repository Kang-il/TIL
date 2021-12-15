#include <iostream>

int GCD(int a,int b){
    if(b==0){
        return a;
    }

    return GCD(b,a%b);
}

int main(){
    //수빈이는 동생 N명과 숨바꼭질을 하고있다 . 1<=N<=100,000
    //수빈이는 점 S에 있고 동생은 A1 A2 An,,, 에 있다
    //1<=S,A<=1,000,000,000
    //수빈이는 1초후에 X->X+D,X-D 로 이동할 수 있다.
    //모든 동생을 찾기 위해 D의 값을 정의하려고 한다 가능한 D의 최대값을 구해보자.

    //동생과 수빈이를 찾을 수 있으려면 D-> 거리의 차이의 약수가 되어야 한다.
    //따라서 동생 N명으로 확장 한다면
    //공통 약수만큼 D를 정한다면 모든 동생을 찾을 수 있다.
    //모든 거리차이의 최대값
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int headCount=0;
    int curPos=0;
    std::cin>>headCount;
    std::cin>>curPos;

    int fir=0;
    std::cin>>fir;
    int result=std::abs(curPos-fir);
    headCount--;

    while(headCount--){
        int sis=0;
        std::cin>>sis;
        int diff=std::abs(curPos-sis);
        result=GCD(result,diff);
    }
    std::cout<<result<<'\n';
    return 0;
}