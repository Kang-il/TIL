#include <iostream>
#include <vector>
#include <algorithm>
#define INT_MAX 2147483647

int W[10][10];
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //(10971)
    //외판원 순회2
    // TSP(Traveling Salesman Problem) -- CS분야에서 가장 중요하게 취급되는 문제 중 하나이다.
    // 가장 일반적인 형태의 문제를 살펴보자
    // 1번 부터 N번 까지 번호가 매겨져 있는 도시들이 있고
    // 도시들 사이에는 길이 있다.(길이 없을 수도 있다.)
    // 이제 한 외판원이 어느 한 도시에서 출발해 N개의 도시를 모두 거쳐 다시 원래의 도시로 돌아오는 순회
    // 여행 경로를 계획하려고 한다.
    // 단. 한 번 갔던 도시로는 다시 갈 수 없다.(맨 마지막에 여행을 출발했던 도시로 돌아오는 것은 예외)
    // 이런 여행경로는 여러가지가 있을 수 있는데 가장 적은 비용을 들이는 여행계획을 세우고자 한다.

    // 각 도시간 이동하는데 드는 비용은 행렬 W[i][j] 형태로 주어진다
    // W[i][j] 는 도시 i에서 도시 j로 가기 위한 비용을 나타낸다.
    // 비용은 대칭적이지 않다. 즉 W[i][j] 는 W[j][i] 와 다를 수 있다.
    // 모든 도시간 비용은 양의 정수이다 
    // W[i][i] 는 항상 0이다.
    // 경우에 따라서 i도시에서 j도시로 갈 수 없는 경우도 있으며 이럴 경우 W[i][j]=0이라고 하자.
    // N과 비용행렬이 주어졌을 때, 가장 적은 비용을 들이는 외판원의 순회 여행경로를 구하는 프로그램을 작성하시오.

    /*
        첫째 줄에 도시의 수 N이 주어진다.
        (2 ≤ N ≤ 10) 다음 N개의 줄에는 비용 행렬이 주어진다. 
        각 행렬의 성분은 1,000,000 이하의 양의 정수이며, 갈 수 없는 경우는 0이 주어진다. 
        W[i][j]는 도시 i에서 j로 가기 위한 비용을 나타낸다.
        항상 순회할 수 있는 경우만 입력으로 주어진다.
    */
    int N;
    std::cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            std::cin>>W[i][j];
        }
    }
    std::vector <int> D(N);
    for(int i=0;i<N;i++){
        D[i]=i;
    }
    int ans=INT_MAX;
    do{
        bool ok=true;
        int sum=0;
        for(int i=0;i<N-1;i++){
            if(W[D[i]][D[i+1]]==0){
                ok=false;
            }else {
                sum+=W[D[i]][D[i+1]];
            }
        }
        if(ok && W[D[N-1]][D[0]]!=0){
            sum+=W[D[N-1]][D[0]];
            if(ans>sum) ans=sum;
        }
        //다음 순열로 바꾸면서 모든 이동 비용을 계산 해 준다.
    }while(std::next_permutation(D.begin()+1,D.end()));
    std::cout<<ans<<'\n';

    return 0;
}