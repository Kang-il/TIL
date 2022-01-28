#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct POINT{
    int x,y;
    POINT(int x,int y):x(x),y(y){}
};
int A,B,C,sum;
bool visited[1000][1000];
void bfs(){
    queue<POINT> q;
    q.push(POINT(A,B));
    visited[A][B]=true;
    while(!q.empty()){
        POINT p=q.front();
        q.pop();
        //A,B 두 수만 사용하면, C는 sum-A-B 로 나타낼 수 있다.
        //합계에서 두 수를 뺀 수가 나머지 한 수
        int z=sum-p.x-p.y;
        // 세 수가 같다면 1 출력 후 종료
        if(p.x==p.y && p.x==z){
            cout<<1<<'\n';
            return;
        }
        // (A,B) (A,C) (B,C) 를 문제에 주어진 조건에 따라 서로 비교한다.
        int D[3][2]{{p.x,p.y},{p.x,z},{p.y,z}};
        for(int i=0;i<3;i++){
            int a=D[i][0];
            int b=D[i][1];
            if(a>b){
                a-=b;
                b+=b;
            }else if(a<b){
                b-=a;
                a+=a;
            }else continue;
            int c=sum-a-b;
            int X=min({a,b,c});
            int Y=max({a,b,c});
            if(!visited[X][Y]){
                q.push(POINT(X,Y));
                visited[X][Y]=true;
            }
        }
    }
    //bfs를 통해 만들 수 없으면 0을 출력한다.
    cout<<0<<'\n';
}
void solve(){
    //나누어 떨어지지 않는다면 만들 수 없는 경우
    if(sum%3!=0){
        cout<<0<<'\n';
        return ;
    }else bfs();
}
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    //(12886)
    // 돌 그룹
    // 오늘 강호는 돌을 이용해 재미있는 게임을 하려고 한다. 
    // 먼저, 돌은 세 개의 그룹으로 나누어져 있으며 각각의 그룹에는 돌이 A, B, C개가 있다.
    // 강호는 모든 그룹에 있는 돌의 개수를 같게 만들려고 한다.

    // 강호는 돌을 단계별로 움직이며, 각 단계는 다음과 같이 이루어져 있다.

    // 크기가 같지 않은 두 그룹을 고른다. 그 다음, 돌의 개수가 작은 쪽을 X, 큰 쪽을 Y라고 정한다. 
    // 그 다음, X에 있는 돌의 개수를 X+X개로, Y에 있는 돌의 개수를 Y-X개로 만든다.

    // A, B, C가 주어졌을 때, 강호가 돌을 같은 개수로 만들 수 있으면 1을, 아니면 0을 출력하는 프로그램을 작성하시오.
    // A,B,C 범위 :: 1 <= A,B,C <= 500
    cin>>A>>B>>C;
    sum=A+B+C;
    solve();
    return 0;
}