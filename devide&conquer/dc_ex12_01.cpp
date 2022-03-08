#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct POINT {
    int x,y;
    POINT(){}
    POINT(int x, int y):x(x),y(y){}
};

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

// 두 점 사이의 거리의 제곱을 반환
int dist(const POINT &u, const POINT &v){
    return pow(u.x-v.x,2) + pow(u.y-v.y,2);
}
// 점 사이 거리 최소값 반환
int brute_force(vector<POINT> &point, int start, int end){
    int ans=-1;
    for(int i=start; i<end;i++){
        for(int j=i+1;j<=end;j++){
            int d= dist(point[i],point[j]);
            if(ans==-1 || ans>d) ans=d;
        }
    }
    return ans;
}

int closest(vector<POINT> &pointA, int start, int end){
    int count = end-start+1;

    if(count<=3){
        return brute_force(pointA,start,end);
    }

    int mid=(start+end)/2;
    //좌우를 나눠 가까운 점을 구한다.
    int left = closest(pointA,start,mid);
    int right = closest(pointA,mid+1,end);
    // 좌 우에서 도출된 거리를 비교하여 최소 거리를 구함.
    int ans=min(left,right);

    // 좌 | 우 분할되어 구했으므로 좌우에 한 개씩 걸쳐있는 점 사이의 거리를 비교한다.
    vector<POINT> pointB;
    for(int i=start;i<=end;i++){
        int d=pointA[i].x-pointA[mid].x;
        // x 좌표 거리 제곱이 ans 보다 작을경우 
        // pointB에 pushBack해준다.
        if(d*d < ans) pointB.push_back(pointA[i]);
    }

    // y좌표를 기준으로 정렬한다.
    sort(pointB.begin(),pointB.end(),[](const POINT &u, const POINT &v){
        return make_pair(u.y,u.x) < make_pair(v.y,v.x);
    });
    
    int m=pointB.size();
    // pointB에 들어있는 좌표 간의 거리를 비교하여 최소값이 있다면 넣어줌.
    for(int i=0 ; i<m-1 ; i++){
        for(int j=i+1;j<m;j++){
            int y=pointB[j].y - pointB[i].y;
            if(y*y < ans){
                int d=dist(pointB[i],pointB[j]);
                if(d<ans) ans=d;
            }else break;
        }
    }
    return ans;
}
void solution(vector<POINT> &point){
    // x좌표를 기준으로 정렬해준다.
    sort(point.begin(),point.end(),[](const POINT &u, const POINT &v){
        return make_pair(u.x,u.y) < make_pair(v.x,v.y);
    });
    cout<< closest(point, 0, N-1) << '\n';
}
int main(){
    //(2261)
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