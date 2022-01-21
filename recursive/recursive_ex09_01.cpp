#include <iostream>
#include <vector>
using namespace std;

struct Work{
    int day;
    int price;
    Work(int day, int price):day(day),price(price){}
};

int N;
int ans=0;
void calc(vector<Work> &table , int day , int price){
    if(day==N){
        //퇴사일이 됐을 때 누적값이 기존 누적값보다 크다면 값을 넣어준다
        if(ans<price) ans=price;
        return ;
    }
    // 퇴사일을 초과한다면 함수 중단.
    if(day>N-1) return;
    //해당 일을 선택하지 않을 경우 day만 +1
    calc(table,day+1,price);
    //해당 일을 선택 햇을 경우 -- 일을 하는데 걸리는 시간을 더해준다.
    //해당 일을 선택 했을 경우 오는 돈을 price 에 더하여 누적시켜준다.
    calc(table,day+table[day].day,price+table[day].price);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //(14501)
     // 퇴사 -- 매개변수 price 를 이용하여 지금까지 벌은 돈의 누적값을 넣어준다.
     // 상담원으로 일하는 백준이가 퇴사를 하려고 한다
     // 오늘부터 N+1일 째 되는 날 퇴사하기위해
     // 남은 N일 동안 최대한 많은 상담을 하려고 한다.
     // 백준이는 비서에게 최대한 많은 상담을 잡으라 부탁했고
     // 비서는 하루에 하나씩 서로 다른 상담을 잡아놓았다
     // dayVec == 해당 상담에 소요되는 일 수
     // price== 해당 상담을 할 경우 받는 돈
     // 상담을 적절히 했을 때, 백준이가 얻을 수 있는 최대 수익을 구하는 프로그램을 작성하시오
     // 1<=N<=15
    cin>>N;
    vector<Work> table;
    for(int i=0;i<N;i++){
        int day,work;
        cin>>day>>work;
        table.push_back(Work(day,work));
    }
    calc(table,0,0);
    cout<<ans<<'\n';
    return 0;
}