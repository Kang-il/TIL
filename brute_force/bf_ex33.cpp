#include <iostream>
#include <vector>
#include <algorithm>
int A[20][20];
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //(14889)
    //스타트와 링크 - 비트마스크 풀이
    // 스타트 링크에 다니는 사람들이 모여서 축구를 해보려고 한다.
    // 축구는 평일 오후에 참석하고 의무참석도 아니다.
    // 축구를 하기 위해 모인 사람은 총 N명이고 N명은 짝수이다.
    // N/2명으로 이루어진 스타트팀과 링크팀으로 사람들을 나눠야 한다.

    // 번호를 1부터 N까지로 배정했고, 아래와 같은 능력치를 조사했다.
    // 능력치 S[i][j]==i번 사람과 j번 사람이 같은 팀에 속했을 때 더해지는 능력치 이다.
    // 팀의 능력치는 팀에 속한 S[i][j]모든 쌍의 능력치의 합이다
    // S[i][j]와 S[j][i] 는 다를 수도 있으며, i번 사람과 j번 사람이 같은팀에 속했을 때
    // 팀에 더해지는 능력치는 S[i][j] 와 S[j][i]다.
    int N;
    std::cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            std::cin>>A[i][j];
        }
    }
    int ans=-1;
    for(int i=0;i<(1<<N);i++){
        std::vector<int> first, second;
        for(int j=0;j<N;j++){
            if(i&(1<<j)){
                first.push_back(j);
            }else{
                second.push_back(j);
            }
        }
        if(first.size()!=N/2) continue;
        int t1=0;
        int t2=0;
        for(int l1=0;l1<N/2;l1++){
            for(int l2=0;l2<N/2;l2++){
                if(l1==l2) continue;
                t1+=A[first[l1]][first[l2]];
                t2+=A[second[l1]][second[l2]];
            }
        }
        int diff=std::abs(t1-t2);
        if(ans==-1 || ans>diff){
            ans=diff;
        }
    }
    std::cout<<ans<<'\n';
    return 0;
}