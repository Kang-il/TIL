#include <iostream>
#include <algorithm>
#define INF 2147483647
using namespace std;

//소요 일수
int t[20];
//얻는 돈
int p[20];
// 해당 일까지 일을 했을 때 누적되는 돈의 최대값을 기록하는 배열
int d[20];
int N;
// DP로 변형하여 풀어보기
// 의미 있는 값 :: 최대수익이 나오는 값
// 특정 날짜가 되면 그다음날부터 
// 어떠한 행위를 하던지 이전의 결과는 영향을 미치지 않는다. -- 다이나믹으로 바꿀 수 있다.
int calc(int day){
    if(day==N) return 0;
    if(day>N) return -INF;
    // 이미 호출 한 적 있는 함수이므로 d[day]를 리턴해준다.
    if(d[day]!=-1) return d[day];
    
    int t1=calc(day+1);
    int t2=p[day]+calc(day+t[day]);
    //최대값을 기록한다. 
    d[day]=max(t1,t2);
    // day일 부터 얻을 수 있는 최대 수익.
    return d[day];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //(14501)
     // 퇴사 -- brute force 문제를 DP로 변형해 풀어보았습니다.
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
    for(int i=0;i<N;i++){
        cin>>t[i]>>p[i];
        d[i]=-1;
    }
    cout<<calc(0)<<'\n';
    return 0;
}