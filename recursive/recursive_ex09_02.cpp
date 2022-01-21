#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2147483647
using namespace std;

struct Work{
    int day;
    int price;
    Work(int day, int price):day(day),price(price){}
};

int N;
//return 값을 이용하는 방식
int calc(vector<Work> &table, int day){
    if(day==N) return 0; //퇴사일 0
    if(day>N) return -INF; //지나면 마이너스 무한대
    //해당 일을 선택하지 않을 경우
    int t1=calc(table,day+1); 
    //해당 일을 선택하는 경우
    int t2=calc(table,day+table[day].day)+table[day].price;
    //최대값을 리턴
    return max(t1,t2);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
     //(14501)
     // 퇴사 -- 매개변수 sum을 이용하지 않고 return 값을 이용하여 문제를 해결하는 방식
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
        int day, work;
        cin>>day>>work;
        table.push_back(Work(day,work));
    }
    int ans=calc(table,0);
    cout<<ans<<'\n';
    return 0;
}