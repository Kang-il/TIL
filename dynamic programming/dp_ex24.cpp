#include <iostream>
#include <vector>

int A[1001];
int main(){
    //(11054)
    // 가장 긴 바이토닉 부분수열
    // 수열 S가 어떤수 Sk를 기준으로 S1 < S2 <...Sk-1 < Sk > Sk+1 > ...Sn-1 > Sn 을 만족한다면
    // 그 수열을 바이토닉 수열이라고 한다.
    // ex>> 10 , 20 , 30 , 25 , 20 은 바이토닉 수열이지만
    //      1 , 2 , 3 , 2 , 1 , 2 , 3 , 2 , 1 은 바이토닉 수열이 아니다.
    // 수열 A가 주어졌을 때 그 수열의 부분수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int N;
    std::cin>>N;
    std::vector<int> UP(N);
    std::vector<int> DOWN(N);
    for(int i=0;i<N;i++){
        std::cin>>A[i];
    }

    //LIS 구해주기
    for(int i=0;i<N;i++){
        UP[i]=1;
        for(int j=0;j<i;j++){
            if(A[i]>A[j] && UP[i]<UP[j]+1){
                UP[i]=UP[j]+1;
            }
        }
    }

    //LDS 구해주기
    for(int i=N-1 ; i>=0 ; i--){
        DOWN[i]=1;
        for(int j=i+1 ; j<N ; j++){
            if(A[i]>A[j] && DOWN[i]<DOWN[j]+1){
                DOWN[i]=DOWN[j]+1;
            }
        }
    }

    int ans=0;
    for(int i=0;i<N;i++){
        //1을 뺀 이유 :: 고점이 중복되므로 길이에 1을 빼줌으로써 중복을 제거한다.
        //고점을 기준으로 (LIS + LDS - 1(고점 중복제거)) 가 가장 긴 값을 ans에 담아준다.
        if(ans < UP[i]+DOWN[i]-1){
            ans=UP[i]+DOWN[i]-1;
        }
    }

    std::cout<<ans<<'\n';

    return 0;
}