#include <iostream>
#include <vector>
#include <algorithm>

bool a[2000][2000];//인접행렬
std::vector<int> g[2000];//인접리스트
std::vector<std::pair<int,int> > edges;//간선리스트
int main(){
    //(13023)
    // ABCDE
    // 0번 부터 N-1 번으로 번호가 매겨져 있고, 일부 사람들은 친구이다.
    // 다음과 같은 친구 관계를 가진사람 A,B,C,D,E가 존재하는지 구해보려고 한다.
    // A와 B는 친구다.
    // B와 C는 친구다.
    // C와 D는 친구다.
    // D와 E는 친구다.
    // 위의 같은 친구관계가 존재하는지 안하는지 구하는 프로그램을 작성하시오.
    // 5<=N<=2000 사람의 수
    // 1<=M<=2000 친구 관계의 수

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N,M;
    std::cin>>N>>M;
    for(int i=0; i<M;i++){
        int from,to;
        std::cin>>from>>to;
        edges.push_back(std::make_pair(to,from));
        edges.push_back(std::make_pair(from,to));
        a[from][to]=a[to][from]=true;
        g[from].push_back(to);
        g[to].push_back(from);
    }

    M*=2;//입력으로 주어진 수 -- 친구 관계 -- 양방향이므로 2배해야됨
    for(int i=0 ; i<M;i++){
        for(int j=0;j<M;j++){
            //A->B
            int A=edges[i].first;
            int B=edges[i].second;
            //C->D
            int C=edges[j].first;
            int D=edges[j].second;

            if(A==B || A==C || A==D || B==C || B==D || C==D) continue;

            //B->C
            if(!a[B][C]) continue;

            for(int E : g[D]){
                if(A==E || B==E || C==E || D==E) continue;
                std::cout<<1<<'\n';
                return 0;
            }
        }
    }
    std::cout<<0<<'\n';
    return 0;
}