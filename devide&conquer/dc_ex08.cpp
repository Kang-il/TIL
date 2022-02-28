#include <iostream>
#include <string>
using namespace std;

int N;
string A;
long long dc,dr;

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>A>>dc>>dr;
}

//해당 사분면의 번호를 row, col로 나타내주는 함수.
pair<long long, long long> findDir(int idx, long long r,  long long c, long long size){
    if(size==1) return {r,c};
    long long m=size/2;
    if(A[idx]=='1') return findDir(idx+1,r,c+m,m);
    else if(A[idx]=='2') return findDir(idx+1,r,c,m);
    else if(A[idx]=='3') return findDir(idx+1,r+m,c,m);
    else if(A[idx]=='4') return findDir(idx+1,r+m,c+m,m);
    return{0,0};
}
//해당 row,col 번호를 사분면 번호로 변환하는 함수
string changePos(long long r, long long c, long long size, long long x, long long y){
    if(size==1) return "";
    long long m=size/2;
    /*
        2 1
        3 4
    */
    if(x<r+m && y<c+m) return "2"+changePos(r,c,m,x,y);
    else if(x<r+m && y>=c+m) return "1"+changePos(r,c+m,m,x,y);
    else if(x>=r+m && y<c+m) return "3"+changePos(r+m,c,m,x,y);
    else return "4"+changePos(r+m,c+m,m,x,y);
}

void solution(){
    // 2^N
    long long size=1LL<<N;
    pair<long long, long long> p=findDir(0,0,0,size);
    // dr :: 상 하 이동 (음수 : 아래로, 양수 : 위로) 
    // dc :: 좌우 이동 (음수: 왼쪽으로, 양수: 오른쪽으로))
    // 위로 이동한 경우가 양수이므로 
    // 부호를 반전시켜줌.
    dr=-dr;
    p.first+=dr;
    p.second+=dc;
    //해당 범위내에 존재 :: 존재하는 사분면일 경우
    if(0<=p.first&&p.first<size&&0<=p.second&&p.second<size){
        cout<<changePos(0,0,size,p.first,p.second)<<'\n';
    }else{
        cout<<"-1\n";
    }
}
int main(){
    // (1891)
    // 사분면
    // 규칙 참고
    // https://www.acmicpc.net/problem/1891
    // 첫 줄에 이동시키려는 사분면 조각 번호의 자릿수를 나타내는 정수 d와, 그 사분면 조각의 번호가 주어진다.
    // (1 ≤ d ≤ 50) 둘째 줄에는 이동의 내용을 나타내는 두 정수가 x, y가 주어진다.
    // (|x|, |y| ≤ 250) 오른쪽으로 이동한 경우 x가 양수, 왼쪽으로 이동한 경우 음수이며,
    // 그 절댓값은 오른쪽 왼쪽 방향 이동 횟수를 나타낸다. 위쪽으로 이동한 경우 y가 양수, 아래쪽으로 이동한 경우 음수이며,
    // 역시 그 절댓값은 아래위 방향 이동 횟수를 나타낸다.
    // 첫 줄에 도착한 사분면의 번호를 출력한다. 만약, 존재하지 않는 사분면인 경우에는 -1을 출력한다.
    input();
    solution();
    return 0;
}