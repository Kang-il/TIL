#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct POINT{
    int x,y;
};
int N;
vector<POINT> A;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    A.resize(N);
    for(int i=0;i<N;i++) cin>> A[i].x >> A[i].y;
}

void solution(){

    sort(A.begin(),A.end(),[](const POINT &u, const POINT &v){
        if(u.y==v.y) return u.x<v.x;
        return u.y<v.y;
    });

    // pair 응용 가능
    // sort(A.begin(),A.end(),[](const POINT &u, const POINT &v){
    //     return make_pair(u.y,u.x) < make_pair(v.y,v.x);
    // });

    for(int i=0;i<N;i++){
        cout<<A[i].x<<' '<<A[i].y<<'\n';
    }
}
int main(){
    // (11651)
    // 좌표 정렬하기 2 - struct, compare
    // 2차원 평면 위의 점 N개가 주어진다.
    // 좌표를 y좌표가 증가하는 순으로,
    // y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

    // 첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다.
    // 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다.
    // (-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.
   
    // 첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다.
    input();
    solution();
    return 0;
}