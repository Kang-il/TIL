#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string str;
int sum;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>str;
    for(char c : str){
        sum+=c-'0';
    }
    return;
}
void solution(){
    // 30의 소인수 2 3 5 -- 얘네 배수가 돼야 함
    // 2의 배수 1의자리 수 :: 2,4,6,8,0
    // 5의 배수 1의자리 수 :: 5,0

    // 30배수의 조건!!!
    // 마지막 숫자가 0
    // 모든자리 다 더한 값이 3의 배수일 때
    sort(str.begin(),str.end());
    if(str[0]=='0' && sum%3==0){
        reverse(str.begin(),str.end());
        cout<<str<<'\n';
    }else cout<<"-1\n";
    return;
}
int main(){
    // (10610)
    // 30
    // 어느 날, 미르코는 우연히 길거리에서 양수 N을 보았다. 
    // 미르코는 30이란 수를 존경하기 때문에, 
    // 그는 길거리에서 찾은 수에 포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수를 만들고 싶어한다.
    // 미르코를 도와 그가 만들고 싶어하는 수를 계산하는 프로그램을 작성하라.

    // N을 입력받는다. N는 최대 105개의 숫자로 구성되어 있으며, 0으로 시작하지 않는다.
    // 미르코가 만들고 싶어하는 수가 존재한다면 그 수를 출력하라. 그 수가 존재하지 않는다면, -1을 출력하라.
    input();
    solution();
    return 0;
}