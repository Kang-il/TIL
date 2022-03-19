#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
double x,y,c;
void input(){
    scanf("%lf %lf %lf",&x,&y,&c);
}
void solution(){
    double left=0;
    double right=min(x,y);
    // left=mid+1;  불가능
    // right=mid-1; 불가능
    // mid-1 mid mid+1 사이에 정답이 있을 수도 있기 때문에 
    // left=mid; right=mid; 로 변경해줌.
    
    // 범위가 0.000001 보다 큰동안 반복한다.
    for(int k=0;k<10000;k++){
        double mid=(left+right)/2.0;
        double d=mid;
        double h1=sqrt(x*x-d*d);
        double h2=sqrt(y*y-d*d);
        double h=(h1*h2)/(h1+h2);
        if(h>c){
            left=mid;
        }else{
            right=mid;
        }
    }
    printf("%.3lf\n",left);
}
int main(){
    //(2022)
    // 사다리
    // 아래의 그림과 같이 높은 빌딩 사이를 따라 좁은 길이 나있다.
    // 두 개의 사다리가 있는데
    // 길이가 x인 사다리는 오른쪽 빌딩의 아래를 받침대로 하여 왼쪽 빌딩에 기대져 있고
    // 길이가 y인 사다리는 왼쪽 빌딩의 아래를 받침대로 하여 오른쪽 빌딩에 기대져 있다.
    // 그리고 두 사다리는 땅에서부터 정확하게 c인 지점에서 서로 교차한다.
    // 그렇다면 두 빌딩은 얼마나 떨어져 있는 걸까?

    // 이미지 참고 ::
    // https://www.acmicpc.net/problem/2022

    // 첫째 줄에 차례대로 x, y, c에 해당하는 양의 실수 세 개가 입력된다.
    // 수는 소수점 여섯째 자리까지 주어질 수 있으며, 3,000,000,000보다 작거나 같다.

    // 두 빌딩사이에 너비가 되는 수치를 출력한다. 절대/상대 오차는 10^-3까지 허용한다.
    input();
    solution();
    return 0;
}