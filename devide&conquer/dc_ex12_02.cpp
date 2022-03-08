#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>
using namespace std;
struct POINT{
    int x, y;
};

bool comp_x(const POINT &u, const POINT &v){
    return make_pair(u.x, u.y) < make_pair(v.x, v.y);
}
bool comp_xe(const POINT &u, const POINT &v){
    return make_pair(u.x, u.y) <= make_pair(v.x, v.y);
}
bool comp_y(const POINT &u, const POINT &v){
    return make_pair(u.y, u.x) < make_pair(v.y, v.x);
}

int N;
vector<POINT> input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    vector<POINT> ret(N);
    for(int i=0;i<N;i++){
        cin>> ret[i].x >> ret[i].y;
    }
    return ret;
}

int dist(const POINT &u, const POINT &v){
    return pow(u.x - v.x, 2) + pow(u.y - v.y ,2);
}

int brute_force(const vector<POINT> &point, int start, int end){
    int ans=-1;
    for(int i=start;i<end;i++){
        for(int j=i+1;j<=end;j++){
            int d = dist(point[i],point[j]);
            if(ans==-1 || d<ans) ans=d;
        }
    }
    return ans;
}

int closest(vector<POINT> &pointX, vector<POINT> &pointY, int start, int end){
    int count=end-start+1;
    if(count<=3){
        return brute_force(pointX, start, end);
    }

    int mid = (start+end)/2;

    POINT mid_p = pointX[mid];
    vector<POINT> pointYL, pointYR;

    // 기준좌표를 중심으로 작으면 pointYL 크거나 같으면 pointYR에 넣어줌
    for(POINT p : pointY){
        if(comp_xe(p,mid_p)){
            pointYL.push_back(p);
        }else{
            pointYR.push_back(p);
        }
    }
    // 좌우거리 중 최소값을 구함.
    int left=closest(pointX,pointYL,start,mid);
    int right=closest(pointX,pointYR,mid+1,end);
    int ans=min(left,right);


    vector<POINT> pointB;
    for(POINT p : pointY){
        //d의 값이 ans보다 작으면 pointB에 push_back
        int d=p.x-mid_p.x;
        if(d*d < ans) pointB.push_back(p);
    }

    int m=pointB.size();
    // 왼쪽점과 오른쪽점에 하나씩 걸쳐있는 점들의 거리가
    // 이전의 좌 , 우에서 거리를 따로 구해 도출된 최소 값보다
    // 작은 값이 나온다면 값을 갱신해줌.
    for(int i=0;i<m-1;i++){
        for(int j=i+1;j<m;j++){
            int y = pointB[j].y-pointB[i].y;
            if(y*y < ans){
                int d=dist(pointB[i],pointB[j]);
                if(d<ans) ans=d;
            }else break;
        }
    }
    return ans;
}

void solution(vector<POINT> &point){
    vector<POINT> pointX,pointY;
    pointX=pointY=point;
    //x좌표를 기준으로 정렬
    sort(pointX.begin(),pointX.end(),comp_x);
    //y좌표를 기준으로 정렬
    sort(pointY.begin(),pointY.end(),comp_y);
    cout<< closest(pointX, pointY, 0, N-1) <<'\n';
}

int main(){
    // (2261)
    // 가장 가까운 두 점
    // 2차원 평면상에 n개의 점이 주어졌을 때, 이 점들 중 가장 가까운 두 점을 구하는 프로그램을 작성하시오.
    // 첫째 줄에 자연수 n(2 ≤ n ≤ 100,000)이 주어진다.
    // 다음 n개의 줄에는 차례로 각 점의 x, y좌표가 주어진다.
    // 각각의 좌표는 절댓값이 10,000을 넘지 않는 정수이다. 여러 점이 같은 좌표를 가질 수도 있다.
    // 첫째 줄에 가장 가까운 두 점의 거리의 제곱을 출력한다.
    vector<POINT> a = input();
    solution(a);
    return 0;
}