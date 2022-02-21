#include <iostream>
#include <vector>
#define MAX 2187
using namespace std;

int N;
int board[MAX][MAX];
int res[3];

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
           cin>>board[i][j];
        }
    }
}
bool same(int x, int y, int n){
    for(int i=x ; i<x+n ; i++){
        for(int j=y ; j<y+n ; j++){
            if(board[i][j] != board[x][y]){
                return false;
            }
        }
    }
    return true;
}
void solution(int x, int y, int n){
    if(same(x,y,n)){
        res[board[x][y]+1]++;
    }else{
        for(int a=x; a<x+n ; a+=n/3){
            for(int b=y ; b<y+n ; b+=n/3){
                solution(a,b,n/3);
            }
        }
    }
}
void print(){
    for(int num : res) cout<<num<<'\n';
}
int main(){
    // (1780)
    // 종이의 개수
    // N×N크기의 행렬로 표현되는 종이가 있다.
    // 종이의 각 칸에는 -1, 0, 1 중 하나가 저장되어 있다.
    // 우리는 이 행렬을 다음과 같은 규칙에 따라 적절한 크기로 자르려고 한다.

    // 1. 만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
    // 2. (1) 이 아닌 경우에는 종이를 같은 크기의 종이 9개로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.

    // 이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수,
    // 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.

    // 첫째 줄에 N(1 ≤ N ≤ 3^7, N은 3^k 꼴)이 주어진다. 다음 N개의 줄에는 N개의 정수로 행렬이 주어진다.
    // 첫째 줄에 -1로만 채워진 종이의 개수를, 둘째 줄에 0으로만 채워진 종이의 개수를, 셋째 줄에 1로만 채워진 종이의 개수를 출력한다.
    input();
    solution(0,0,N);
    print();
    return 0;
}