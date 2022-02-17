#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string S,T;
string tmp;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>S>>T;
}
void solution(string s, string t){
    if(s==t) {
        cout<<"1\n";
        exit(0);    
    }
    if(s.size()>t.size()) return ;
    if(t.back()=='A'){
        tmp=t;
        tmp.pop_back();
        solution(s,tmp);
    }
    if(t.front()=='B'){
        tmp=t;
        reverse(tmp.begin(),tmp.end());
        tmp.pop_back();
        solution(s,tmp);
    }
}
int main(){
    // (12919)
    // A와 B 2
    // 수빈이는 A와 B로만 이루어진 영어 단어 존재한다는 사실에 놀랐다.
    // 대표적인 예로 AB (Abdominal의 약자), BAA (양의 울음 소리), 
    // AA (용암의 종류), ABBA (스웨덴 팝 그룹)이 있다.

    // 이런 사실에 놀란 수빈이는 간단한 게임을 만들기로 했다. 
    // 두 문자열 S와 T가 주어졌을 때, S를 T로 바꾸는 게임이다. 
    // 문자열을 바꿀 때는 다음과 같은 두 가지 연산만 가능하다.

    // 문자열의 뒤에 A를 추가한다.
    // 문자열의 뒤에 B를 추가하고 문자열을 뒤집는다.
    // 주어진 조건을 이용해서 S를 T로 만들 수 있는지 없는지 알아내는 프로그램을 작성하시오. 

    // 첫째 줄에 S가 둘째 줄에 T가 주어진다. (1 ≤ S의 길이 ≤ 49, 2 ≤ T의 길이 ≤ 50, S의 길이 < T의 길이)
    // S를 T로 바꿀 수 있으면 1을 없으면 0을 출력한다.
    input();
    solution(S,T);
    cout<<"0\n";
    return 0;
}