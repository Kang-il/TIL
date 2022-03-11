#include <iostream>
using namespace std;
int N;
long long K;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N>>K;
}
long long calc(int n){
    long long ans=0;
    for(int start=1,len=1 ; start<=n ; start*=10,len++){
        int end = start*10-1;
        if(end>n) end=n;
        ans+=(long long)(end-start+1)*len;
    }
    return ans;
}
void solution(){
    if (calc(N) < K){
        cout<<-1<<'\n';
        return;
    }
    int left=1;
    int right=N;
    int ans=0;
    while(left<=right){
        int mid = (left+right)/2;
        long long len = calc(mid);
        if(len<K){
            left=mid+1;
        }else{
            ans=mid;
            right=mid-1; 
        }
    }
    string str = to_string(ans);
    long long l = calc(ans);
    cout<<str[str.length()-(l-K)-1]<<'\n';
}
int main(){
    // (1790)
    // 수 이어쓰기 2
    // 1부터 N까지의 수를 이어서 쓰면 다음과 같이 새로운 하나의 수를 얻을 수 있다.
    // 1234567891011121314151617181920212223...
    // 이렇게 만들어진 새로운 수에서, 앞에서 k번째 자리 숫자가 어떤 숫자인지 구하는 프로그램을 작성하시오.
    // 첫째 줄에 N(1 ≤ N ≤ 100,000,000)과,  k(1 ≤ k ≤ 1,000,000,000)가 주어진다. 
    // N과 k 사이에는 공백이 하나 이상 있다.
    // 첫째 줄에 앞에서 k번째 자리 숫자를 출력한다.
    // 수의 길이가 k보다 작아서 k번째 자리 숫자가 없는 경우는 -1을 출력한다.
    input();
    solution();
    return 0;
}