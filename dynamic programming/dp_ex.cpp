#include <iostream>

int D[12];
int go(int N){
    if(N==0){
        return 1;
    }
    if(N==1){
        return 1;
    }
    if(N==2){
        return 2;
    }
    if(N==3){
        return 4;
    }

    if(D[N]>0) return D[N];
    D[N]=go(N-1)+go(N-2)+go(N-3);

    return D[N];
}

int main(){
    //(9095)
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
    // 1.2.3 n-1 n-2 n-3
    //D[n]=D[n-1]+d[n-2]+d[n-3]
    int n;
    std::cin>>n;
    while(n--){
        int num;
        std::cin>>num;
        std::cout<<go(num)<<'\n';
    }

    return 0;
}