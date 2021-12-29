#include <iostream>
#include <algorithm>
#include <string>

int board[4][4];
int main(){
    //(14391)
    // 종이조각
    // 숫자가 쓰여있는 직사각형 종이를 가지고 있다.
    // 종이는 1x1크기의 정사각형으로 칸이 나누어져있고, 숫자는 각 칸에 하나씩 쓰여있다.
    // 행은 위에서 아래까지 번호가 매겨져 있고, 열은 왼쪽부터 오른쪽까지 번호가 매겨져 있다.
    // 직사각형을 겹치지 않는 조각으로 자르려고 한다.
    // 한 조각은 크기가 세로나 가로 크기가 1인 직사각형 모양이다.
    // 길이가 N인 조각은 N자리 수로 나타낼 수 있다.
    // 가로 조각은 왼쪽부터 오른쪽까지 수를 이어붙인 것이고
    // 세로 조각은 위에서부터 아래까지 수를 이어 붙인 것이다.
    // 종이를 적절히 잘라서 조각의 합을 최대로 하는 프로그램을 작성하시오.
    int N,M;
    std::cin>>N>>M;
    for(int i=0;i<N;i++){
            std::string str;
            std::cin>>str;
            int idx=0;
            for(int j=0;j<M;j++){
                board[i][j]=str[j]-'0';
            }
    }
    int ans=0;
    for(int s=0;s<(1<<(N*M));s++){
        int sum=0;
        for(int i=0;i<N;i++){
            int cur=0;
            for(int j=0;j<M;j++){
                int k = i*M+j;
                if((s&(1<<k))==0){
                    cur=cur*10+board[i][j];
                }else{
                    sum+=cur;
                    cur=0;
                }
            }
            sum+=cur;
        }

        for(int j=0;j<M;j++){
            int cur=0;
            for(int i=0;i<N;i++){
                int k=i*M+j;
                if((s&(1<<k))!=0){
                    cur=cur*10+board[i][j];
                }else{
                    sum+=cur;
                    cur=0;
                }
            }
            sum+=cur;
        }
        ans=std::max(ans,sum);
    }
    std::cout<<ans<<'\n';
    return 0;
}