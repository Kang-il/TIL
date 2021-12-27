#include <iostream>
#include <vector>
#include <algorithm>

int A[20][20];
int N;

int go(int idx, std::vector<int> first, std::vector<int> second){
    if(first.size()>N/2) return -1;
    if(second.size()>N/2) return -1;
    if(idx==N){
        int t1=0;
        int t2=0;
        for(int i=0;i<N/2;i++){
            for(int j=0;j<N/2;j++){
                t1+=A[first[i]][first[j]];
                t2+=A[second[i]][second[j]];
            }
        }
        int diff=std::abs(t1-t2);
        return diff;
    }

    int ans=-1;
    first.push_back(idx);
    int t1=go(idx+1,first,second);
    if(ans==-1 || (t1!=-1 && ans>t1)){
        ans=t1;
    }
    first.pop_back();
    second.push_back(idx);
    int t2=go(idx+1,first,second);
    if(ans==-1 || (t2!=-1 && ans>t2)){
        ans = t2;
    }
    second.pop_back();

    return ans;
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //(14889)
    //스타트와 링크
    // 스타트 링크에 다니는 사람들이 모여서 축구를 해보려고 한다.
    // 축구는 평일 오후에 참석하고 의무참석도 아니다.
    // 축구를 하기 위해 모인 사람은 총 N명이고 N명은 짝수이다.
    // N/2명으로 이루어진 스타트팀과 링크팀으로 사람들을 나눠야 한다.

    // 번호를 1부터 N까지로 배정했고, 아래와 같은 능력치를 조사했다.
    // 능력치 S[i][j]==i번 사람과 j번 사람이 같은 팀에 속했을 때 더해지는 능력치 이다.
    // 팀의 능력치는 팀에 속한 S[i][j]모든 쌍의 능력치의 합이다
    // S[i][j]와 S[j][i] 는 다를 수도 있으며, i번 사람과 j번 사람이 같은팀에 속했을 때
    // 팀에 더해지는 능력치는 S[i][j] 와 S[j][i]다.
    std::cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            std::cin>>A[i][j];
        }
    }
    std::vector<int> first;
    std::vector<int> second;
    int ans = go(0,first,second);
    std::cout<<ans<<'\n';
    return 0;
}