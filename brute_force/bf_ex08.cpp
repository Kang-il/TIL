#include <iostream>

bool visited[10];
int A[10];
void go(int idx,int N,int M){
    //idx == M이라면 만들고자 하는 수열의 길이조건이 충족되었으므로 출력해준다.
    if(idx==M){
        for(int i=0;i<M;i++){
            std::cout<<A[i];
            if(i!=M-1) std::cout<<" ";
        }
        std::cout<<'\n';
        return;
    }
    //1부터 N까지 수열을 만들어주는 for 문
    for(int i=1;i<=N;i++){
        //현재 숫자가 쓰였다면 continue;
        if(visited[i]) continue;
        //현재 숫자가 쓰이지 않았다면
        //방문여부에 true 넣어주고
        visited[i]=true;
        //A의 인덱스에 for 문 인덱스 i값을 넣어주고
        A[idx]=i;
        //함수 재 호출
        go(idx+1,N,M);
        //함수가 끝나면 방문여부를 false 로 초기화 시켜준다.
        visited[i]=false;
    }
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    //(15649)
    // N 과 M (1)
    // 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
    //1. 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
    // 첫째 줄에 자연수 N 과 M이 주어진다.(1<=M<=N<=8)
    // 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다.
    // 중복되는 수열을 여러번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
    // 수열은 사전 순으로 증가하는 순서로 출력해야 한다.

    int N,M;
    std::cin>>N>>M;
    go(0,N,M);

    return 0;
}