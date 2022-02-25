#include <iostream>
#include <vector>
using namespace std;
int N,R,C;
int ans;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>R>>C;
}
void solution(int x, int y, int size){
    if(x == R && y == C) {
        cout<<ans<<'\n';
        return;
    }
    if(R < x+size && R >= x && C < y+size && C >= y){
        solution(x, y, size/2);
        solution(x, y+size/2, size/2);
        solution(x+size/2, y, size/2);
        solution(x+size/2, y+size/2, size/2);
    }else{
        ans+=size*size;
    }
}
int main(){
    //(1074)
    // Z
    // 한수는 크기가 2N × 2N인 2차원 배열을 Z모양으로 탐색하려고 한다.
    // 예를 들어, 2×2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.
    // 이미지 참고
    // https://www.acmicpc.net/problem/1074
    // 첫째 줄에 정수 N, R, C가 주어진다.
    // R행 C열을 몇 번째로 방문 했는지 출력한다.
    // 1 ≤ N ≤ 15
    // 0 ≤ r, c < 2^N
    input();
    // (1<<N) 2의 N승을 표현
    solution(0,0,(1<<N));
    return 0;
}