#include <iostream>


int house[1001][3];
int costs[1001][3];
int main(){
    //(17404)
    //RGB 거리 2
    // RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집 부터 N번 집이 순서대로 있다.
    // 집은 빨,초,파 중 하나의 색으로 칠해야 한다.
    // 각각의 집을 빨,초,파로 칠하는 비용이 주어졌을 때
    // 아래 규칙을 만족하면서 모든집을 칠하는 비용의 최솟값을 알아보자.

    //1. 1번 집의 색은 2번,N번 집의 색과 같지 않아야 한다.
    //2. N번 집의 색은 N-1번, 1번 집의 색과 같지 않아야한다.
    //3. i(2<=i<=N-1) 번 집의 색은ㅇ i-1,i+1번 집의 색과 같지 않아야 한다.

    //원형마을이라는 뜻이다.
    //1.직선 -> 원형으로 바꿔준다.
    //1번 집의 색상을 고정하고 풀도록 해본다.
    //1. 원형이 아니라고 생각 후 하나를 고정하고 문제를 풀어보면 된다
    // 다이나믹을 총 3번 수행한다.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int N;
    std::cin>>N;

    for(int i=1; i<=N ; i++){
        for(int j=0 ; j<3 ; j++){
            std::cin>>costs[i][j];
        }
    }

    int ans=1000*1000+1;

    for(int k=0;k<=2;k++){
        //고정작업
        for(int j=0;j<=2;j++){
            if(j==k){
                house[1][j]=costs[1][j];
            }else{
                house[1][j]=1000*1000+1;
            }
        }

        for(int i=2;i<=N;i++){
            house[i][0]=std::min(house[i-1][1],house[i-1][2])+costs[i][0];
            house[i][1]=std::min(house[i-1][0],house[i-1][2])+costs[i][1];
            house[i][2]=std::min(house[i-1][0],house[i-1][1])+costs[i][2];
        }

        for(int j=0;j<=2;j++){
            //1번 집과 n번 집이 같은 경우 건너뛴다.
            if(j==k) continue;
            ans=std::min(house[N][j],ans);
        }
    }

    std::cout<<ans<<'\n';

    return 0;
}