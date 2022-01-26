#include <iostream>
#include <queue>
using namespace std;
struct KNIGHT{
    int x,y,count;
    KNIGHT(int x, int y,int count):x(x),y(y),count(count){}
};
//이동규칙
int D[6][2]{{-2,-1},{-2,1},{0,-2},{0,2},{2,-1},{2,1}};
bool board[200][200];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //(16948)
    // 데스나이트
    // 게임을 좋아하는 큐브러버는 체스에서 사용할 새로운 말 "데스 나이트"를 만들었다. 
    // 데스 나이트가 있는 곳이 (r, c)라면, 
    // (r-2, c-1), (r-2, c+1), (r, c-2), (r, c+2), (r+2, c-1), (r+2, c+1)로 이동할 수 있다.
    // 크기가 N×N인 체스판과 두 칸 (r1, c1), (r2, c2)가 주어진다. 
    // 데스 나이트가 (r1, c1)에서 (r2, c2)로 이동하는 최소 이동 횟수를 구해보자. 
    // 체스판의 행과 열은 0번부터 시작한다.
    // 데스 나이트는 체스판 밖으로 벗어날 수 없다.
    // 첫째 줄에 체스판의 크기 N(5 ≤ N ≤ 200)이 주어진다. 둘째 줄에 r1, c1, r2, c2가 주어진다.

    // 첫째 줄에 데스 나이트가 (r1, c1)에서 (r2, c2)로 이동하는 최소 이동 횟수를 출력한다. 
    // 이동할 수 없는 경우에는 -1을 출력한다.
    int N;
    cin>>N;
    //최초위치
    int x,y;
    //목적지
    int dx,dy;
    cin>>x>>y;
    cin>>dx>>dy;
    queue<KNIGHT> q;
    //최초위치 push
    q.push(KNIGHT(x,y,0));
    //최초 위치 방문 체크
    board[x][y]=true;

    int ans=-1;
    while(!q.empty()){
        KNIGHT k=q.front();
        q.pop();
        //목적지 도착시
        if(k.x==dx && k.y==dy){
            //최소값 넣어주기
            if(ans==-1 || ans>k.count) ans=k.count;
        }
        //이동해보기
        for(int i=0;i<6;i++){
            int nx=k.x+D[i][0];
            int ny=k.y+D[i][1];
            //체스판 범위 내에서만 이동하도록
            if(nx<0 || ny<0 || nx>N-1 || ny>N-1) continue;
            //방문한 적 있으면 건너뛰기 -- 최소값 (이전에 방문한 적을 방문할 경우 최소값이 아님)
            if(board[nx][ny]) continue;
            //방문체크 하고 해당 위치 push
            board[nx][ny]=true;
            q.push(KNIGHT(nx,ny,k.count+1));
        }
    }
    cout<<ans<<'\n';
    return 0;
}