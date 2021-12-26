#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

std::vector<char> cVec;
bool check(std::string str){
    // 사용된 자음과 모음의 개수를 세어서
    // 조건에 부합하는 패스워드인지 확인 한 후 true/false 값을 반환한다.
    int vowN=0;
    int contN=0;
    for(char c : str){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
            vowN++;
        }else{
            contN++;
        }
    }
    return vowN>=1 && contN>=2;
}

void go(int N, std::vector<char> &alph ,std::string password, int idx){
    // N == 만들어야 하는 암호의 길이
    // alph ==  사용할 수 있는 알파벳
    // password 현재까지 만든 암호
    // i 사용할지 말지 결정해야 하는 알파멧의 인덱스
    
    //만들고자 하는 암호의 길이와 만든 패스워드의 길이가 일치하는 경우 출력해준다.
    if(password.length()==N){
        if(check(password)){
            // 조건에 부함한 패스워드라면 출력.
            std::cout<<password<<'\n';
        }
        return;
    }
    //인덱스가 alph 벡터의 길이가 같거나 넘는 순간 더이상 사용할 알파벳이 없다.
    //함수를 벗어난다.
    if(idx>=alph.size()) return;

    // 불가능 한 경우
    // 문제의 조건을 위배 한 경우
    // 재귀호출을 하더라도 문제를 못푸는 경우
    // 사용할 수 있는 알파벳의 제한 idx>= alph.size()

    // 현재 알파벳 추가/제외 두 가지의 조건을 분기하여 함수 호출
    go(N,alph,password+alph[idx],idx+1);
    go(N,alph,password,idx+1);
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
    for(int i=0;i<C;i++){
        std::cin>>cVec[i];
    }
    std::sort(cVec.begin(),cVec.end());
    go(L,cVec,"",0);
    
    return 0;
}