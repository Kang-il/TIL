#include <iostream>

int A[3];
int D[3]{1,1,1};
int main(){
    //(1476)
    //날짜계산
    //수 3개를 이용해 연도를 나타낸다.
    // 세 수를 E,S,M이라고 했을 때 각각의 범위
    // 1 <= E <= 15 
    // 1 <= S <= 28
    // 1 <= M <= 19
    // 1 년 ::: 1 1 1
    // 2 년 ::: 2 2 2
    // 15년 ::: 15 15 15
    // 16년 ::: 1 16 16
    // 해당 자리 수의 범위가 넘어간다면 1이 된다.
    // E S M이 표시되는 가장 빠른 연도를 출력한다.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    for(int i=0;i<3;i++){
        std::cin>>A[i];
    }

    for(int i=1;;i++){
        if(A[0]==D[0] && A[1]==D[1] && A[2]==D[2]){
            std::cout<<i<<'\n';
            break;
        }
        D[0]+=1;
        D[1]+=1;
        D[2]+=1;
        if(D[0]==16){
            D[0]=1;
        }
        if(D[1]==29){
            D[1]=1;
        }
        if(D[2]==20){
            D[2]=1;
        }
    }
    return 0;
}