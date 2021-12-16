#include <iostream>

long long D[1000001][4];
const int limit = 100000;
const long long mod=1000000009LL;
int main(){
    //15990
    // 정수 4를 1,2,3의 합으로 나타내는 방법은 총 3가지가 있다.
    // 합을 나타낼 때는 수를 1개 이상 사용해야 한다.
    // 단, 같은 수를 두 번이상 연속해서 사용할 수 없다.

    // 첫째 줄 -- 테스트케이스 수 T가 주어진다.
    // 각 테스트케이스는 한 줄로 이루어져있고, 정수 n이 주어진다.
    // n은 양수이며 100,000보다 작거나 같다.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
 
    for(int i=1;i<=limit;i++){
        if(i-1>=0){
            D[i][1]=D[i-1][2]+D[i-1][3];
            if(i==1){
                D[i][1]=1;
            }
        }
        if(i-2>=0){
            D[i][2]= D[i-2][1]+D[i-2][3];
            if(i==2){
                D[i][2]=1;
            }
        }
        if(i-3>=0){
            D[i][3]=D[i-3][1]+D[i-3][2];
            if(i==3){
                D[i][3]=1;
            }
        }

        D[i][1]%=mod;
        D[i][2]%=mod;
        D[i][3]%=mod;
    }

    int T;
    std::cin>>T;

    while(T--){
        int num;
        std::cin>>num;
        std::cout<<(D[num][1]+D[num][2]+D[num][3]) % mod << '\n';
        
    }

    return 0;
}