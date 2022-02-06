#include <iostream>
using namespace std;
int N,M;
int A[50][50];
int B[50][50];
void flip(int x, int y){
    for(int i=x-1;i<=x+1;i++){
        for(int j=y-1;j<=y+1;j++){
            A[i][j]=1-A[i][j];
        }
    }
}

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        for(int j=0;j<M;j++){
            A[i][j]=str[j]-'0';
        }
    }
    
    for(int i=0;i<N;i++){
        string str;
        cin>>str;
        for(int j=0;j<M;j++){
            B[i][j]=str[j]-'0';
        }
    }
}

void solution(){
    int ans=0;
    for(int i=0;i<N-2;i++){
        for(int j=0;j<M-2;j++){
            if(A[i][j]!=B[i][j]){
                ans+=1;
                flip(i+1,j+1);
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(A[i][j]!=B[i][j]){
                cout<<-1<<'\n';
                return;
            }
        }
    }
    cout<<ans<<'\n';
    return;
}

int main(){
    // (1080)
    // 행렬
    // 0과 1로만 이루어진 행렬 A와 행렬 B가 있다. 
    // 이때, 행렬 A를 행렬 B로 바꾸는데 필요한 연산의 횟수의 최솟값을 구하는 프로그램을 작성하시오.
    // 행렬을 변환하는 연산은 어떤 3×3크기의 부분 행렬에 있는 모든 원소를 뒤집는 것이다. (0 → 1, 1 → 0)
    // 첫째 줄에 행렬의 크기 N M이 주어진다. N과 M은 50보다 작거나 같은 자연수이다. 
    // 둘째 줄부터 N개의 줄에는 행렬 A가 주어지고, 그 다음줄부터 N개의 줄에는 행렬 B가 주어진다.
    // 첫째 줄에 문제의 정답을 출력한다. 바꿀 수 없다면 -1을 출력한다.
    input();
    solution();
    return 0;
}