#include <iostream>
#include <vector>
#include <algorithm>

int ans=0;
int N;
void resultCal(std::vector<int> &vec){
    int tmp=0;
    for(int i=1;i<N;i++){
        tmp+=std::abs(vec[i-1]-vec[i]);
    }
    if(ans<tmp) ans=tmp;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // (10819)
    // 차이를 최대로
    // N개의 정수로 이루어진 배열 A가 주어진다.
    // 이 때 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식의 
    // 최대값을 구하는 프로그램을 작성하시오
    // |A[0]-A[1]|+|A[1]=A[2]|+...+A[N-2]+A[N-1]|
    // 배열에 들어있는 수의 순서를 적절히 바꿔서 얻을 수 있는 식의 최대값을 출력한다. 


    // N의 범위 3<=N<=8 -- 모두 8 * 8! --> 모든 순열을 구하여 계산하여도 제한시간 안에 풀 수 있다. 
    std::cin>>N;
    std::vector<int> aVec(N);
    for(int i=0;i<N;i++){
        std::cin>>aVec[i];
    }

    std::sort(aVec.begin(),aVec.end());
    
    do{
        resultCal(aVec);
    }while(std::next_permutation(aVec.begin(),aVec.end()));

    std::cout<<ans<<'\n';
    
    return 0;
}