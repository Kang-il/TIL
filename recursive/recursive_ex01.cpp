#include <iostream>
#include <vector>

int N;
std::vector<int> ans;
//함수 호출 시 답이 오름차순으로 나오게 됨.
void go(std::vector<int> &a, int idx, int cnt){
    if(cnt==6){
        for(int num : ans){
            std::cout<<num << ' ';
        }
        std::cout<<'\n';
        return;
    }
    if(idx==a.size()) return;
    //1. 선택한 경우
    ans.push_back(a[idx]);
    go(a,idx+1,cnt+1);
    ans.pop_back();
    //2. 선택하지 않는 경우
    go(a,idx+1,cnt);
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //(6603)
    // 독일 로또는 {1,2,...,49} 에서 6개를 고른다
    // 로또 번호를 선텍하는데 사용되는 가장 유명한 전략은
    // 49가지 수 중 k(k>6)개의 수를 골라 집합 S를 만든 다음 그 수만 가지고 번호를 선택하는 것이다.
    // 예를 들어, k=8, S={1,2,3,5,8,13,21,34}인 경우 이 집합 S에서 수를 고를 수 있는 경우의 수는 
    // 총 28가지이다. ([1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34])
    // 집합 S와 k가 주어졌을 때, 수를 고르는 모든 방법을 구하는 프로그램을 작성하시오.
    while(true){
        // 첫 번째 수 6<= N <=13
        // 다음 N개의 수는 집합에 포함되는 수 이며 오름차순으로 주어진다.
        // 입력의 마지막에는 0이 하나 주어진다.
        std::cin>>N;
        if(N==0) break;
        std::vector<int> lotto(N);
        //수가 항상 오름차순으로 입력됨.
        for(int i=0;i<N;i++){
            std::cin>>lotto[i];
        }
        go(lotto,0,0);
        std::cout<<'\n';
    }
    return 0;
}