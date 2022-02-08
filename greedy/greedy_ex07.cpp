#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<string> board;
char flip (char c){
    if(c=='H') return 'T';
    else return 'H';
}
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    board.resize(N);
    for(int i=0;i<N;i++){
        cin>>board[i];
    }
    return;
}
void solution(){
    int ans=N*N;
    for(int i=0;i<(1<<N);i++){
        int sum=0;
        for(int j=0;j<N;j++){
            int cnt=0;
            for(int k=0;k<N;k++){
                char cur=board[j][k];
                if(i&(1<<k)){
                    cur=flip(cur);
                }
                if(cur=='T'){
                    cnt++;
                }
            }
            sum+=min(cnt,N-cnt);
        }
        if(ans>sum)ans=sum;
    }
    cout<<ans<<'\n';
    return ;
}
int main(){
    // (1285)
    // 동전뒤집기
    // N2개의 동전이 N행 N열을 이루어 탁자 위에 놓여 있다. 
    // 그 중 일부는 앞면(H)이 위를 향하도록 놓여 있고, 나머지는 뒷면(T)이 위를 향하도록 놓여 있다.
    // https://www.acmicpc.net/problem/1285 -- 그림 / 설명 참고
    // N2개의 동전들의 초기 상태가 주어질 때, 
    // 한 행 또는 한 열에 놓인 N개의 동전을 모두 뒤집는 작업들을 수행하여 뒷면이 위를 향하는 동전 개수를 최소로 하려 한다. 
    // 이때의 최소 개수를 구하는 프로그램을 작성하시오.
    // 첫째 줄에 20이하의 자연수 N이 주어진다. 
    // 둘째 줄부터 N줄에 걸쳐 N개씩 동전들의 초기 상태가 주어진다. 
    // 각 줄에는 한 행에 놓인 N개의 동전의 상태가 왼쪽부터 차례대로 주어지는데, 
    // 앞면이 위를 향하도록 놓인 경우 H, 뒷면이 위를 향하도록 놓인 경우 T로 표시되며 이들 사이에 공백은 없다.
    // 첫째 줄에 한 행 또는 한 열에 놓인 N개의 동전을 모두 뒤집는 
    // 작업들을 수행하여 뒷면이 위를 향하여 놓일 수 있는 동전의 최소 개수를 출력한다.
    input();
    solution();
    return 0;
}