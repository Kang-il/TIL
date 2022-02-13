#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string S,T;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>S>>T;
}
void solution(){
    while(true){
        // 만들고자 하는 문자열에 해당 규칙이 적용되어있다고 가정하여
        // 이를 기준으로 규칙을 역으로 적용해 바꾸어 보고 (삭제)
        // (처음 문자열과 길이가 같아질 때 까지 규칙을 역으로 적용)
        // 길이가 같아졌을 때 두 문자열이 동일하면 만들 수 있는 문자열
        // 동일하지 않다면 만들 수 없는 문자열이다.
        if(T.back() == 'B'){
            T.pop_back();
            reverse(T.begin(),T.end());
        }else if(T.back() == 'A'){
            T.pop_back();
        }
        if(T.length() == S.length()){
            if(T == S) cout<<"1\n";
            else cout<<"0\n";
            break;
        }
    }
    return ;
}
int main(){
    // (12904)
    // A와 B
    // 수빈이는 A와 B로만 이루어진 영어 단어가 존재한다는 사실에 놀랐다. 
    // 대표적인 예로 AB (Abdominal의 약자), BAA (양의 울음 소리), AA (용암의 종류), ABBA (스웨덴 팝 그룹)이 있다.

    // 이런 사실에 놀란 수빈이는 간단한 게임을 만들기로 했다. 
    // 두 문자열 S와 T가 주어졌을 때, S를 T로 바꾸는 게임이다. 
    // 문자열을 바꿀 때는 다음과 같은 두 가지 연산만 가능하다.

    // 1. 문자열의 뒤에 A를 추가한다.
    // 2. 문자열을 뒤집고 뒤에 B를 추가한다.
    
    // 주어진 조건을 이용해서 S를 T로 만들 수 있는지 없는지 알아내는 프로그램을 작성하시오.
    // 첫째 줄에 S가 둘째 줄에 T가 주어진다. (1 ≤ S의 길이 ≤ 999, 2 ≤ T의 길이 ≤ 1000, S의 길이 < T의 길이)
    // S를 T로 바꿀 수 있으면 1을 없으면 0을 출력한다.
    input();
    solution();
    return 0;
}