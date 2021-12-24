#include <iostream>

int go( int sum, int goal){
    // 조건에 위배 되는 경우
    if(sum > goal) return 0;
    //조건에 부합한다면 1을 반환 -- 경우의 수 1개 추가.
    if(sum==goal) return 1;
    
    int now=0;
    for(int i=1; i<=3;i++){
        now+=go(sum+i,goal);
    }
    return now;
}

int main(){
     //(9095)
     // 1 2 3 더하기
     /*
         정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 
         합을 나타낼 때는 수를 1개 이상 사용해야 한다.
         1+1+1+1
         1+1+2
         1+2+1
         2+1+1
         2+2
         1+3
         3+1
         정수 n이 주어졌을 때, n을 1, 2, 3의 
         합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
         첫째 줄에 테스트케이스의 개수 T가 주어진다. 각 테스트케이스는 한 줄로 이루어져 있고,
         정수 n이 주어진다 n은 양수이며 11보다 작다.
     */

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int T;
    std::cin>>T;
    while(T--){
        int N;
        std::cin>>N;
        std::cout<<go(0,N)<<'\n';
    }
    return 0;
}