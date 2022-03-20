#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
struct DOT{
    double x,y,z;
};
pair<DOT,DOT> line;
DOT dot;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>line.first.x>>line.first.y>>line.first.z;
    cin>>line.second.x>>line.second.y>>line.second.z;
    cin>>dot.x>>dot.y>>dot.z;
}

double dist(double x1, double y1, double z1, double x2, double y2, double z2){
    double x=(x2-x1) * (x2-x1);
    double y=(y2-y1) * (y2-y1);
    double z=(z2-z1) * (z2-z1);
    return sqrt(x+y+z);
}

void solution(){
    double dx=line.second.x-line.first.x;
    double dy=line.second.y-line.first.y;
    double dz=line.second.z-line.first.z;

    double left=0.0;
    double right=1.0;
    double m=0;

    while(true){
        if(abs(left-right)<1e-9){
            m=(left+right)/2;
            break;
        }

        double m1=left + (right-left)/3;
        double m2=right - (right-left)/3;

        double m1x=line.first.x + m1 * dx;
        double m1y=line.first.y + m1 * dy;
        double m1z=line.first.z + m1 * dz;

        double m2x=line.first.x + m2 * dx;
        double m2y=line.first.y + m2 * dy;
        double m2z=line.first.z + m2 * dz;
        
        double d1=dist(m1x, m1y, m1z, dot.x, dot.y, dot.z);
        double d2=dist(m2x, m2y, m2z, dot.x, dot.y, dot.z);

        if(d1>d2){
            left=m1;
        }else{
            right=m2;
        }
    }

    double x0 = line.first.x + m * dx;
    double y0 = line.first.y + m * dy;
    double z0 = line.first.z + m * dz;
    double ans = dist(x0, y0, z0, dot.x, dot.y, dot.z);
    cout << fixed << setprecision(10) << ans <<'\n';
}

int main(){
    // (11664)
    // 선분과 점
    // 3차원 좌표 평면 위에 선분 하나와 점 하나가 있다. 
    // 선분의 양 끝점은 A(Ax, Ay, Az)와 B(Bx, By, Bz)로 나타낼 수 있다.
    // 점의 좌표는 C(Cx, Cy, Cz) 이다.

    // 선분과 점 사이의 거리의 최솟값을 구하는 프로그램을 작성하시오.

    // 두 점 (x1, y1, z1)과 (x2, y2, z2) 사이의 거리는 
    // sqrt((x2-x1) * (x2-x1) + (y2-y1) * (y2-y1) + (z2-z1) * (z2-z1));

    // 첫째 줄에 선분과 점의 좌표 Ax, Ay, Az, Bx, By, Bz, Cx, Cy, Cz가 주어진다.
    // 좌표는 0보다 크거나 같고, 10,000보다 작거나 같은 정수이다.
    // 첫째 줄에 선분과 점 사이의 거리의 최솟값을 출력한다. 절대/상대 오차는 10^-6까지 허용한다.

    input();
    solution();
    return 0;
}