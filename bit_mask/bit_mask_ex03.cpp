#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define LIMIT 10
//기울인다는 연산 -- 2번이상 이동하는 것은 의미가 없다.
// 1.최초 경우 -- 4
//   두 번째 경우 -- 3
// 전 방향으로 이동한 다음 반대방향으로 이동하는 것은 의미가 없다.
// 4*2^9 = 2048 가지
int D[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
vector<int> gen(int k){
    vector<int> a(LIMIT);
    for(int i=0;i<LIMIT;i++){
        a[i]=(k&3);
        k>>=2;
    }
    return a;
}
pair<bool,bool> simulate(vector<string> &a, int k, int &x, int &y){
    if(a[x][y]=='.') return make_pair(false,false);
    int N=a.size();
    int M=a[0].size();
    bool moved=false;
    while(true){
        int nx=x+D[k][0];
        int ny=y+D[k][1];
        if(nx<0 || ny<0 || nx>=N || ny>=M) return make_pair(moved,false);

        if(a[nx][ny]=='#'){
            return make_pair(moved,false);
        }else if(a[nx][ny]=='R' || a[nx][ny]=='B'){
            return make_pair(moved,false);
        }else if(a[nx][ny]=='.'){
            swap(a[nx][ny],a[x][y]);
            x=nx;
            y=ny;
            moved=true;
        }else if(a[nx][ny]=='O'){
            a[x][y]='.';
            moved=true;
            return make_pair(moved,true);
        }
    }
    return make_pair(false,false);
}
int check(vector<string> a,vector<int> &dir){
    int N=a.size();
    int M=a[0].size();
    int hx,hy,rx,ry,bx,by;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(a[i][j]=='O'){
                hx=i;
                hy=j;
            }else if(a[i][j]=='R'){
                rx=i;
                ry=j;
            }else if(a[i][j]=='B'){
                bx=i;
                by=j;
            }
        }
    }
    int cnt=0;
    for(int k : dir){
        cnt+=1;
        bool hole1=false,hole2=false;
        while(true){
            auto p1=simulate(a,k,rx,ry);
            auto p2=simulate(a,k,bx,by);
            if(p1.first==false && p2.first==false) break;
            if(p1.second) hole1=true;
            if(p2.second) hole2=true;
        }
        if(hole2) return -1;
        if(hole1) return cnt;
    }
    return -1;
}
bool valid (vector<int> &dir){
    int l=dir.size();
    for(int i=0;i+1<l;i++){
        if(dir[i]==0 && dir[i+1]==1) return false;
        if(dir[i]==1 && dir[i+1]==0) return false;
        if(dir[i]==2 && dir[i+1]==3) return false;
        if(dir[i]==3 && dir[i+1]==2) return false;
        if(dir[i]==dir[i+1]) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // (13460)
    // 구슬 탈출 2 - 비트마스크 풀이
    // 스타트링크에서 판매하는 어린이용 장난감 중에서 가장 인기가 많은 제품은 구슬 탈출이다. 
    // 구슬 탈출은 직사각형 보드에 빨간 구슬과 파란 구슬을 하나씩 넣은 다음, 
    // 빨간 구슬을 구멍을 통해 빼내는 게임이다.
    // 보드의 세로 크기는 N, 가로 크기는 M이고, 편의상 1×1크기의 칸으로 나누어져 있다. 
    // 가장 바깥 행과 열은 모두 막혀져 있고, 보드에는 구멍이 하나 있다. 
    // 빨간 구슬과 파란 구슬의 크기는 보드에서 1×1크기의 칸을 가득 채우는 사이즈이고, 각각 하나씩 들어가 있다. 
    // 게임의 목표는 빨간 구슬을 구멍을 통해서 빼내는 것이다. 이때, 파란 구슬이 구멍에 들어가면 안 된다.
    // 이때, 구슬을 손으로 건드릴 수는 없고, 중력을 이용해서 이리 저리 굴려야 한다. 
    // 왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기와 같은 네 가지 동작이 가능하다.
    // 각각의 동작에서 공은 동시에 움직인다. 
    // 빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패이다. 
    // 빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다. 빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다. 
    // 또, 빨간 구슬과 파란 구슬의 크기는 한 칸을 모두 차지한다. 
    // 기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.
    // 보드의 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램을 작성하시오.
    int N,M;
    cin>>N>>M;
    vector<string> a(N);
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    int ans=-1;
    for(int k=0;k<(1<<(LIMIT*2));k++){
        vector<int> dir=gen(k);
        if(!valid(dir)) continue;
        int cur=check(a,dir);
        if(cur==-1) continue;
        if(ans==-1 || ans>cur) ans=cur;
    }
    cout<<ans<<'\n';
    return 0;
}