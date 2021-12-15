#include <iostream>
#include <string>

int main(){
    //ROT13(11655)
    // ROT13은 카이사르 암호의 일종으로 영어 알파벳을 13글자씩 밀어서 만든다.
    // ex> "Baekjoon Online Judge" -> "Onrxwbba Bayvar Whqtr"
    // ROT13 으로 암호화 한 내용을 원래 내용으로 바꾸려면 암호화한 문자열을 다시 ROT13하면 된다.
    // ROT13은 알파벳 대문자와 소문자에만 적용 가능하다.
    // ex> "One is 1" -> "Bar vf 1"
    // 숫자나 공백은 그대로 출력한다.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    std::string str;
    getline(std::cin,str);

    for(int i=0;i<str.length();i++){
        if(str[i]>='a' && str[i]<='m'){
            str[i]=str[i]+13;
        }else if(str[i]>='n' && str[i]<='z'){
            str[i]=str[i]-13;
        }else if(str[i]>='A' && str[i]<='M'){
            str[i]=str[i]+13;
        }else if(str[i]>='N' && str[i]<='Z'){
            str[i]=str[i]-13;
        }
    }
    std::cout << str <<'\n';

    return 0;
}