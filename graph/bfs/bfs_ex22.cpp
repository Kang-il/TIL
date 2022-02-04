#include <iostream>
#include <tuple>
#include <queue>
#include <string>
#include <set>
using namespace std;
const long long MAX=1000000000LL;
long long s,t;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s>>t;
}
int main(){
    // (14395)
    // 4연산
    // 정수 s가 주어진다. 정수 s의 값을 t로 바꾸는 최소 연산 횟수를 구하는 프로그램을 작성하시오.
    // 사용할 수 있는 연산은 아래와 같다.
    // s = s + s; (출력: +)
    // s = s - s; (출력: -)
    // s = s * s; (출력: *)
    // s = s / s; (출력: /) (s가 0이 아닐때만 사용 가능)
    // 첫째 줄에 s와 t가 주어진다. (1 ≤ s, t ≤ 10^9)
    // 첫째 줄에 정수 s를 t로 바꾸는 방법을 출력한다. 
    // s와 t가 같은 경우에는 0을, 바꿀 수 없는 경우에는 -1을 출력한다. 
    // 가능한 방법이 여러 가지라면, 사전 순으로 앞서는 것을 출력한다. 
    // 연산의 아스키 코드 순서는 '*', '+', '-', '/' 이다.
    input();
    set<long long> check;
    queue<pair<long long, string>> q;
    q.push(make_pair(s,""));
    while(!q.empty()){
        long long x;
        string str;
        tie(x,str)=q.front();
        q.pop();
        if(x==t){
            if(str.length()==0){
                str="0";
            }
            cout<<str<<'\n';
            return 0;
        }
        if(x*x >= 0  && x*x<=MAX && check.count(x*x)==0){
            q.push(make_pair(x*x,str+"*"));
            check.insert(x*x);
        }
        if(x+x>=0 && x+x<=MAX && check.count(x+x)==0){
            q.push(make_pair(x+x,str+"+"));
            check.insert(x+x);
        }
        if(x-x >= 0 && x-x <= MAX && check.count(x-x)==0){
            q.push(make_pair(x-x,str+"-"));
            check.insert(x-x);
        }
        if(x!=0 && x/x >= 0 && x/x<=MAX && check.count(x/x)==0){
            q.push(make_pair(x/x,str+"/"));
            check.insert(x/x);
        }
    }
    cout<<-1<<'\n';
    return 0;
}