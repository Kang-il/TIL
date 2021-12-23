#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> aVec;
int A[10];
void go(int idx,int start,int N,int M){
    if(idx==M){
        for(int i=0;i<M;i++){
            std::cout<<A[i];
            if(i!=M-1) std::cout<<" ";
        }
        std::cout<<'\n';
        return;
    }

    for(int i=start ; i<N ; i++ ){
        A[idx]=aVec[i];
        go(idx+1,i,N,M);
    }

}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    //(15657)
    //N과 M (8)
    // N개의 자연수와 M이 주어졌을 때 아래 조건을 만족하는 길이가 M인 수열을
    // 모두 구하는 프로그램을 작성하시오.
    // N개의 자연수는 모두 다른 수이다.
    // N개의 자연수 중에서 M개를 고른 수열
    // 같은 수를 여러번 골라도 된다.
    // 고른 수열은 비내림차순이어야 한다.
    // 길이가 K인 수열 A가 A1<=A2<=...<=Ak-1 <=Ak를 만족하면 비내림차순이라고 한다.

    int N,M;
    std::cin>>N>>M;
    aVec.resize(N);
    for(int i=0;i<N;i++){
        std::cin>>aVec[i];
    }

    std::sort(aVec.begin(),aVec.end());
    go(0,0,N,M);
    return 0;
}