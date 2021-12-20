#include <iostream>

int D[1001];
int A[1001];
int main(){
    //(11722)
    //가장 긴 감소하는 부분수열
    //수열 A가 주어졌을 때 가장 긴 감소하는 부분수열의 길이를 구하는 프로그램을 작성하시오
    //ex> A=[10,30,10,20,20,10] [30,20,10] 이고 길이는 3이다.
    //첫째 줄에 수열 A의 크기 1 <= N <= 1000
    //둘 째 줄에 수열 A를 이루고있는 수가 주어진다 1<= A <= 1000
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin>>N;
    //애초 값을 받을 때 배열에 반대로 값을 받을 것이다.
    for(int i=N;i>0;i--){
        std::cin>>A[i];
    }
    //수열을 반대로 뒤집은 이유
    //배열을 뒤집고 나서 가장 긴 증가하는 부분수열의 길이를 구하면
    //가장 긴 감소하는 부분수열을 구하는 것과 같다.
    int max=0;
    for(int i=1;i<=N;i++){
        D[i]=1;
        for(int j=1;j<i;j++){
            if(A[i]>A[j] && D[i]<D[j]+1){
                D[i]=D[j]+1;
            }
        }
        if(max<D[i]) max=D[i];
    }

    std::cout<<max<<'\n';
    return 0;
}