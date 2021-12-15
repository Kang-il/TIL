#include <iostream>
#include <stack>
#include <string>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //백준 1918
    // 후위 표기식
    // 후위 표기법 (postfix notation) -- 연산자가 피연산자 뒤에 위치하는 것.
    // ex > a+b -> ab+
    // 중위 표기식이 입력값으로 들어올 경우 후위표기식으로 수정 출력하는 프로그램을 만들어라.

    std::string str;
    std::cin>>str;

    std::stack<char> stk;
    int len = str.length();
    for(int i=0;i<len;i++){
        char c=str[i];

        if(c>='A' && c<='Z'){
            std::cout<<c;
        }else if(c=='(') {
            stk.push(c);
        }else if(c==')'){
            while(stk.top()!='('){
                std::cout<<stk.top();
                stk.pop();
            }
            stk.pop();
        }else if(c=='+' || c=='-'){
            while(!stk.empty() && stk.top()!='('){
                std::cout<<stk.top();
                stk.pop();
            }
            stk.push(c);
        }else if(c=='*' || c=='/'){
            while(!stk.empty() && (stk.top()=='*' || stk.top()=='/')){
                std::cout<<stk.top();
                stk.pop();
            }
            stk.push(c);
        }
    }

    while(!stk.empty()){
        std::cout<<stk.top();
        stk.pop();
    }
    std::cout<<'\n';

    return 0;
}