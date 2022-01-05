#include <iostream>
#include <vector>
#include <algorithm>

int N;
int S[10][10];
int A[10];

bool ok(int idx){
    int sum=0;
    for(int i=idx;i>=0;i--){
        sum+=A[i];
        if(S[i][idx]==0 && sum!=0) return false;
        if(S[i][idx]>0 && sum <=0) return false;
        if(S[i][idx]<0 && sum>=0) return false;
    }
    return true;
}

bool go (int idx){
    if(idx==N) return true;
    if(S[idx][idx]==0){
        A[idx]=0;
        return ok(idx) && go(idx+1);
    }
    for(int i=1;i<=10;i++){
        A[idx]=S[idx][idx]*i;
        if(ok(idx)&& go(idx+1)) return true;
    }
    return false;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //(1248)
    // 맞춰봐
    // -10 부터 10까지 N개의 정수로 이루어진 수열이 있다 (N<=10)
    // S[i][j]=A[i]+A[i+1]+...+A[j]가 0보다 크면 +, 0보다 작으면 -, 0이면 0
    // S가 주어졌을 때 가능한 A를 아무거나 찾는 문제
    // i는 j보다 항상 작거나 같다.
    std::string str;
    std::cin>>N;
    std::cin>>str;
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            if(str[cnt]=='+'){
                S[i][j]=1;
            }
            if(str[cnt]=='-'){
                S[i][j]=-1;
            }
            if(str[cnt]=='0'){
                S[i][j]=0;
            }
            cnt++;
        }
    }
    go(0);
    for(int i=0;i<N;i++){
        std::cout<<A[i]<<' ';
    }
    std::cout<<'\n';

    return 0;
}