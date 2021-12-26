#include <iostream>
#include <vector>
#include <algorithm>

std::vector<char> cVec;
std::vector<bool> visited;
char A[15];
void go(int idx ,int start, int C, int L, int vowCnt, int conCnt){
    if(idx==L && vowCnt>=1 && conCnt >= 2){
        for(int i=0;i<L;i++){
            std::cout<<A[i];
        }
        std::cout<<'\n';
        return;
    }
    for(int i=start;i<C;i++){
        if(visited[i]) continue;
        visited[i]=true;
        char tmp=cVec[i];
        A[idx]=tmp;
        if(tmp=='a' || tmp == 'e' || tmp=='i' || tmp =='o' || tmp=='u'){
            go(idx+1,i,C,L,vowCnt+1,conCnt);
        }else{
            go(idx+1,i,C,L,vowCnt,conCnt+1);
        }
        visited[i]=false;       
    }
    
}

int main(){
    //(1759)
    // 암호 만들기
    // 방 열쇠 주머니를 넣은채 깜빡하고 서울로 간 최백준 조교 때문에
    // 702호에 새로운 보안시스템을 설치하기로 했다.
    // 암호로 동작하게 되어있는 시스템이다
    // 암호는 서로다른 L개의 알파벳 소문자들로 구성되며 최소 한 개의 모음
    // (a , e , i , o , u)과 최소 두 개의 자음으로 구성되어 있다고 알려져 있다.
    // 또한 정렬된 문자열을 선호하는 조교들의 성향으로 미루어 보아 암호를 이루는 알파벳이
    // 암호에서 증가하는 순서로 배열되었을 것이라고 추측된다.
    // 즉 abc는 가능성이 있지만 bac는 그렇지 않다.
    // 새 보안시스템에 조교들이 암호로 사용했을 법 한 문자의 종류는 C가지가 있다.
    // 이 알파벳을 입수한 민식,영식은 형제 조교들의 방에 침투하기 위해
    // 암호를 추측해 보려고 한다.
    // C개의 문자들이 모두 주어졌을 때, 가능성 있는 암호들을 모두 구하는
    // 프로그램을 작성하시오.

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // 3<=L<=C<=15
    int L,C;
    std::cin>>L>>C;
    cVec.resize(C);
    visited.resize(C);
    for(int i=0;i<C;i++){
        std::cin>>cVec[i];
    }
    std::sort(cVec.begin(),cVec.end());
    go(0,0,C,L,0,0);

    return 0;
}