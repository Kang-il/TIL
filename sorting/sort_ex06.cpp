#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;

int N;
int cnt[MAX+1];
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        cnt[tmp]+=1;
    }
}
void solution(){
    for(int i=1;i<=MAX;i++){
        if(cnt[i]>0) {
            for(int j=0;j<cnt[i];j++){
                cout<< i << '\n';
            }
        }
    }
}
int main(){
    // (10989)
    // 수 정렬하기 3
    // N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오
    // 첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다.
    // 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.
    
    // 입력받은 수를 전부 다 입력받아 저장하게 되면 제한된 8MB의 메모리를 초과해 버린다.
    // 숫자를 카운트 해 두었다 출력만 해주는 방식을 사용
    input();
    solution();
    return 0;
}