#include <iostream>
#include <vector>
#include <algorithm>

bool c[20*100000+10];
int N;
int board[20];
std::vector<int> aVec;
void go(int idx, int sum){
    if(idx==N){
        c[sum]=true;
        return;
    }
    go(idx+1,sum+board[idx]);
    go(idx+1,sum);
}
int main(){ 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //(14225)
    // 부분수열의 합
    // 수열 S가 주어졌을 때, 수열 S의 부분수열의 합으로 나올 수 없는 
    // 가장 작은 자연수를 구하는 프로그램을 작성하시오
    // 예를 들어, S = [5, 1, 2]인 경우에 
    // 1, 2, 3(=1+2), 5, 6(=1+5), 7(=2+5), 8(=1+2+5)을 만들 수 있다. 
    // 하지만, 4는 만들 수 없기 때문에 정답은 4이다.
    std::cin>>N;

    for(int i=0;i<N;i++){
        std::cin>>board[i];
    }

    go(0,0);

    int start=1;
    for(int i=1;;i++){
        if(c[i]==false){
            std::cout<< i <<'\n';
            break;
        }
    }
    return 0;
}