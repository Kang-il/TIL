#include <iostream>
#include <string>

using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //괄호
    // 괄호 문자열이 주어졌을 때, 올바른 괄호 문자열인지 아닌지를 알아보는 문제
    // 괄호 문자열 '(' 와 ')'로만 이루어진 문자열
    // 올바른 괄호문자열 : 괄호의 쌍이 올바른 문자열 문제

    // 1. 여는괄호와 닫는 괄호 특 :: 쌍이 엉키는 경우가 없다.
    // -- 가장가까운 여는괄호 닫는 괄호가 짝을 이룬다.
    // 여는괄호 닫는괄호 쌍.
    // 모든 닫는 괄호에 대하여 여는 괄호를 찾는다.
    //      1. 닫는괄호의 앞에있는 여는괄호
    //      2. 다른 여는괄호와 짝을 이루지 않는 것
    //      3. 1,2 모두 해당되면 가장 가까운 여는괄호

    // 스택 -- 후입선출..LIFO
    // 스택 -- 여는괄호만 넣는것(정답의 후보)
    // 다른 여는괄호만 짝이맞지 않는애들만 넣는다
    // 닫는괄호앞에 있는 여는괄호

    string str="(()(()))";
    int cnt=0;

    for(int i=0;i<str.size();i++){
        if(str[i]=='(')
            cnt+=1;
        else   
            cnt-=1;
        
        if(cnt<0){
            cout<<"NO"<<endl;
        }
    }

    if(cnt == 0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    



    return 0;
}