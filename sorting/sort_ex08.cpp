#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
vector<pair<int,int>> A;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    A.resize(N);
    for(int i=0;i<N;i++){
        cin>>A[i].first;
        A[i].second=i;
    }
}
void solution(){
    sort(A.begin(),A.end());
    int result=0;
    for(int i=0 ; i<N ; i++){
        result = max(result, A[i].second-i);
    }
    cout<<result+1<<'\n';
}
int main(){
    // (1377)
    // 버블소트
    /*
        버블 소트 알고리즘을 다음과 같이 C++로 작성했다.

        bool changed = false;
        for (int i=1; i<=N+1; i++) {
            changed = false;
            for (int j=1; j<=N-i; j++) {
                if (A[j] > A[j+1]) {
                    changed = true;
                    swap(A[j], A[j+1]);
                }
            }
            if (changed == false) {
                cout << i << '\n';
                break;
            }
        }
        위 소스에서 N은 배열의 크기이고, A는 정렬해야 하는 배열이다. 배열은 A[1]부터 사용한다.

        위와 같은 소스를 실행시켰을 때, 어떤 값이 출력되는지 구해보자.
    
    */
    input();
    solution();
    return 0;
}