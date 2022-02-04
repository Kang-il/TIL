#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#define MAX 10001
using namespace std;
bool prime[MAX];
bool visited[MAX];
int dist[MAX];
int T,N,M;
//에라토스테네스의 체
void prime_check(){
    for(int i=2;i<MAX;i++){
        if(prime[i]==false){
            for(int j=i*i ; j<MAX;j+=i){
                prime[j]=true;
            }
        }
    }
    for(int i=0;i<MAX;i++){
        prime[i]=!prime[i];
    }
    return;
}
void input(){
    cin>>N>>M;
    memset(visited,false,sizeof(visited));
    memset(dist,0,sizeof(dist));
}
int change(int num, int idx, int digit){
    //천의자리 수가 0이면 3자리 수가 되므로 -1 리턴
    if(idx==0 && digit == 0 ) return -1;
    string str=to_string(num);
    str[idx]=digit+'0';
    return stoi(str);

}
void solution(){
    input();
    dist[N]=0;
    visited[N]=true;
    queue<int> q;
    q.push(N);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            for(int j=0;j<=9;j++){
                int next=change(now,i,j);
                if(next!=-1){
                    if(prime[next]&&visited[next]==false){
                        q.push(next);
                        dist[next]=dist[now]+1;
                        visited[next]=true;
                    }
                }
            }
        }
    }
    cout<<dist[M]<<'\n';
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // (1963)
    // 소수경로
    // 소수를 유난히도 좋아하는 창영이는 게임 아이디 비밀번호를 4자리 ‘소수’로 정해놓았다. 어느 날 창영이는 친한 친구와 대화를 나누었는데:

    // “이제 슬슬 비번 바꿀 때도 됐잖아”
    // “응 지금은 1033으로 해놨는데... 다음 소수를 무엇으로 할지 고민중이야"
    // “그럼 8179로 해”
    // “흠... 생각 좀 해볼게. 이 게임은 좀 이상해서 비밀번호를 한 번에 한 자리 밖에 못 바꾼단 말이야. 예를 들어 내가 첫 자리만 바꾸면 8033이 되니까 소수가 아니잖아. 여러 단계를 거쳐야 만들 수 있을 것 같은데... 예를 들면... 1033 1733 3733 3739 3779 8779 8179처럼 말이야.”
    // “흠...역시 소수에 미쳤군. 그럼 아예 프로그램을 짜지 그래. 네 자리 소수 두 개를 입력받아서 바꾸는데 몇 단계나 필요한지 계산하게 말야.”
    // “귀찮아”
    // 그렇다. 그래서 여러분이 이 문제를 풀게 되었다. 
    // 입력은 항상 네 자리 소수만(1000 이상) 주어진다고 가정하자. 
    // 주어진 두 소수 A에서 B로 바꾸는 과정에서도 항상 네 자리 소수임을 유지해야 하고, 
    // ‘네 자리 수’라 하였기 때문에 0039 와 같은 1000 미만의 비밀번호는 허용되지 않는다.
    
    cin>>T;
    prime_check();
    while(T--){
        solution();
    }
    return 0;
}