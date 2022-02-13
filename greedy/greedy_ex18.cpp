#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// M :: 최대 증가하는 부분수열 길이
// K :: 최대 감소하는 부분수열 길이
int N,M,K;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>M>>K;
    return;
}

void solution(){
    // 적어도 M개의 정수는 증가수열에 포함되어야 하고
    // 적어도 K개의 정수는 감소 수열에 포함되어야 한다.
    // 두 수열은 최대 정수 1개 공유할 수 있다.

    // N >= M+K-1

    // N은 M*K를 넘을 수 없다
    // N = M*K+1 인 경우
    // 길이가 M+1인 증가수열이나
    // 길이가 K+1인 감소수열을 반드시 만들 수 있다.
    // --- 비둘기 집의 원리)))

    // 따라서 
    // M+K-1 <= N <= M*K 인 경우에만 답을 찾을 수 있다.

    // 그룹의 크기  :: 감소의 길이
    // 그룹의 개수 :: 증가하는 부분수열의 길이

    // 적어도 하나의 그룹은 K개의 수가 있어야 함
    // 모든 그룹은 K보다 작거나 같아야 한다!!
    if( M+K-1 <= N && N <= M*K ){

        vector<int> ans(N);

        for(int i = 0 ; i < N ; i++){
            ans[i]=i+1;
        }

        //그룹의 경계를 담아줌
        // 이를 기준으로 뒤집기 할 것임.
        vector<int> group;
        // 0-K 까지 :: 뒤집을경우 
        // K사이즈의 감소하는 부분수열 완성
        group.push_back(0);
        group.push_back(K);

        N-=K;
        //그룹 하나 만들었으니 -1
        M-=1;

        int group_size = M == 0 ? 1 : N/M;
        int rest = M == 0 ? 0 : N%M;

        for(int i=0 ; i < M ; i++){
            group.push_back(group.back() + group_size + (rest > 0 ? 1 : 0));
            if(rest > 0) --rest;
        }
        for(int i = 0 ; i < group.size()-1 ; i++){
            reverse(ans.begin()+group[i] , ans.begin()+group[i+1]);
        }

        for(int i = 0 ; i < ans.size() ; i++){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';

    }else cout<<"-1\n";
}

int main(){
    // (1201)
    // NMK
    // 1부터 N까지의 수를 한 번씩 이용해서 가장 긴 증가하는 부분 수열의 길이가 M이고, 
    // 가장 긴 감소하는 부분 수열의 길이가 K인 수열을 출력한다.
    // 첫째 줄에 세 정수 N M K 가 주어진다.

    // 첫째 줄에 문제의 조건을 만족하는 수열을 출력한다. 
    // 만약, 조건을 만족하는 수열이 없다면 -1을 출력한다.

    // 1 ≤ N ≤ 500
    // 1 ≤ M, K ≤ N
    input();
    solution();

    return 0;
}