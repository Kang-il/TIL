#include <iostream>
#include <string>
#include <stack>


void print(std::stack<char> &s){
    while(!s.empty()){
        std::cout<<s.top();
        s.pop();
    }
}
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
    bool tag=false;
    std::stack<char> stk;
    for(char ch : str){
        if(ch=='<'){
            print(stk);
            tag=true;
            std::cout<<ch;
        }else if(ch=='>'){
            tag=false;
            std::cout<<ch;
        }else if(tag){
            std::cout<<ch;
        }else {
            if(ch==' '){
                print(stk);
                std::cout<<ch;
            }else {
                stk.push(ch);
            }
        }
    }
    print(stk);
    std::cout<<'\n';
    return 0;
}