#include <iostream>
#include <vector>

//N퇴사까지 남은 일수
//idx 고른 일
//total -- 총 돈

int N;
std::vector<int> dayVec;
std::vector<int> price;
int ans;
void go(int day, int sum){
    if(day==N){
        if(ans<sum) ans=sum;
        return;
    }
    if(day>N) return;
    //day :: 오는 날
    //sum :: 총 상담비용
    //1. 정답을 찾은 경우
    //2. day>N+1 인경우 조건 불합
    // 다음 경우 호출

    // 1. 상담 하는경우
    go(day+dayVec[day],sum+price[day]);
    // 2. 이날 상담을 선택하지 않은 경우
    go(day+1,sum);
}

int main(){
    //(14501)
    // 퇴사
    // 상담원으로 일하는 백준이가 퇴사를 하려고 한다
    // 오늘부터 N+1일 째 되는 날 퇴사하기위해
    // 남은 N일 동안 최대한 많은 상담을 하려고 한다.
    // 백준이는 비서에게 최대한 많은 상담을 잡으라 부탁했고
    // 비서는 하루에 하나씩 서로 다른 상담을 잡아놓았다
    // dayVec == 해당 상담에 소요되는 일 수
    // price== 해당 상담을 할 경우 받는 돈
    // 상담을 적절히 했을 때, 백준이가 얻을 수 있는 최대 수익을 구하는 프로그램을 작성하시오
    // 1<=N<=15
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>N;
    dayVec.resize(N);
    price.resize(N);

    for(int i=0;i<N;i++){
        std::cin>>dayVec[i];
        std::cin>>price[i];
    }

    go(0,0);
    std::cout<<ans<<'\n';
    return 0;
}