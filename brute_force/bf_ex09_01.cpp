#include <iostream>

bool visited[10];
int A[10];
//1. 방문여부를 표시하여 수열에 수를 포함할 지 하지 않을 지 정해주는 방법.
void go(int idx,int start, int N,int M){
   if(idx==M){
       for(int i=0;i<M;i++){
           std::cout<<A[i];
           if(i!=M-1) std::cout<<" ";
       }
       std::cout<<'\n';
       return;
   }
    // 1-N 에서 start수를 정하고 ++한다면 이전의 수는 수열에서 제외되므로 자연스럽게 
    // 오름차순으로 정렬되어있는 수열만 만들 수 있다.
   for(int i=start;i<=N;i++){
       if(visited[i]) continue;
       visited[i]=true;
       A[idx]=i;
       go(idx+1,i+1,N,M);
       visited[i]=false;
   }
}

int main(){
    //(15650)
    // N과 M(2)
    // 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는
    // 프로그램을 작성하시오
    // 1. 1 부터 N 까지 자연수 중에서 중복없이 M개를 고른 수열
    // 2. 고른 수열은 오름차순 이어야 한다.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int visitedCount=0;
    int N,M;
    std::cin>>N>>M;

    go(0,1,N,M);
    
    return 0;
}