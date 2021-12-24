#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //(10972)
    // 다음순열
    // 다음 순열 1 부터 N까지의 수로 이루어진 순열이 있다. 이때 사전 순으로 다음에 오는 순열을
    // 구하는 프로그램을 작성하시오
    // 사전순으로 가장 앞서는 순열은 오름차순으로 이루어진 순열이고,
    // 가장 마지막으로 오는 순열은 내림차순으로 이루어진 순열이다.

    // 사전순으로 다음에 오는 순열과 이전에 오는 순열을 찾는 방법
    // C++ STL 의 algorithm에는 이미 
    // next_permutation 과 prev_permutation이 존재하기 때문에 사용하면 된다.
    // 반환값: bool 타입 :: 다음이나 이전의 순열이 없다면 false 반환 // 있다면 true 반환.
    // java 경우엔 없으니 직접 구현해서 사용해야 한다.
    int N;
    std::cin>>N;
    std::vector<int> aVec(N);
    for(int i=0;i<N;i++){
        std::cin>>aVec[i];
    }

    if(std::next_permutation(aVec.begin(),aVec.end())){
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