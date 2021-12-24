#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> D;
void printLotto(std::vector<int> &vec){
    int cnt=0;
    for(int i=0;i<vec.size();i++){
        if(D[i]==0){
            std::cout<<vec[i];
        if(cnt!=5) std::cout<<' ';
        cnt++;
        }
    }
    std::cout<<'\n';
    return;
}
int main(){
    //(6603)
    //로또
    // 독일 로또는 {1,2,...,49}에서 수 6개를 고른다.
    // 로또 번호를 선택하는데 가장 유명한 전략은 29가지의 수 중 k(k>6개의 수를 골라 집합 S를 만든 다음
    // 그 수만 가지고 번호를 선택하는 것이다
    // 예를 들어 k=8, S={1,2,3,5,8,13,21,34}인 경우에 이 집함 S에서 수를 고를 수 있는 경우의 수는
    // 총 28가지이다.
    // 집합 S와 k가 주어졌을 때 수를 고르는 모든 방법을 구하는 프로그램을 작성하시오
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::vector<int> aVec;

    while(true){
        int K;
        std::cin>>K;
        //마지막에 K에 0이 입력된다면 
        // loop 벗어나기
        if(K==0){
            break;
        }

        aVec.resize(K);
        D.resize(K);
        
        //D의 0은 선택한 수
        //D의 1은 선택하지 않은 수

        for(int i=0;i<K;i++){
            std::cin>>aVec[i];
            if(i<=5){//최초 6자리까지는 1을 넣어주고
                D[i]=0;
            }else{// 이후 남은 자리는 0 을 넣어줌 
                D[i]=1;
            }
        }
        // 로또 번호를 작은 수 부터 정렬 해 준다.
        std::sort(aVec.begin(),aVec.end());
        do
        {   //do while 문을 통해 로또 번호 출력
            printLotto(aVec);
            // 0 0 0 0 0 0 1....1k-1 1k 이므로 
            // 1 1 1 1 1 .... 0 0 0 0 0 0 가 될때 까지
            // 출력 해주면 해당 배열에서 로또 번호의 모든 경우를 출력 할 수 있다.
        } while (std::next_permutation(D.begin(),D.end()));
        std::cout<<'\n';
    }

    return 0;
}