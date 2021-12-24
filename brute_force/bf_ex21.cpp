#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    //(10973)
    // 이전순열
    // 1부터 N까지의 수로 이루어진 순열이 있다.
    // 이때, 사전순으로 바로 이전에 오는 순열을 구하는 프로그램을 작성하시오.
    // 사전 순으로 가장 앞서는 순열은 오름차순으로 이루어진 순열이고,
    // 가장 마지막에 오는 순열은 내림차순으로 이루어진 순열이다.

    int N;
    std::cin>>N;
    std::vector<int> aVec(N);
    for(int i=0;i<N;i++){
        std::cin>>aVec[i];
    }
    if(std::prev_permutation(aVec.begin(),aVec.end())){
        for(int i=0;i<N;i++){
            std::cout<<aVec[i];
            if(i!=N-1) std::cout<<' ';
        }
        std::cout<<'\n';
    }else{
        std::cout<<-1<<'\n';
    }
    return 0;
}