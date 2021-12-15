#include <iostream>
#include <stack>
#include <string>

int main(){
    //단어뒤집기
    //알파벳 소문자, 숫자, 공백, 특수문자 (<,>)로 이루어진 문자열 S에서 
    //단어를 뒤집는 문제,
    //태그 <로 시작해서 >로 끝나는 문자열, 사이에는 알파벳 소문자와 공백만 있음
    //단어와 단어 사이에는 공백 한 칸, 단어와 태그 사이에는 공백이 없음.
    //<open>tag<close> -> <open>gat<close>
    //<ab cd>ef gh<ij kl>
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
  
    std::string str;
    getline(std::cin,str);

    bool tagChek=false;
    std::stack<char> stk;

    for(char c : str){
        if(c=='<'){
            tagChek=true;
            while(!stk.empty()){
                std::cout<<stk.top();
                stk.pop();
            }
            std::cout<<c;

            continue;
        }

        if(c=='>'){
            tagChek=false;
            std::cout<<c;
            continue;
        }

        if(tagChek){
            std::cout<<c;
        }else{
            if(c==' ' || c=='\n' || c=='>'){
                while(!stk.empty()){
                    std::cout<<stk.top();
                    stk.pop();
                }
            }else{
                stk.push(c);
                continue;
            }
            std::cout<<c;
        }
    }

    while(!stk.empty()){
        std::cout<<stk.top();
        stk.pop();
    }

    return 0;
}