#include <iostream>
#include <string>

int main(){
    //문자열 분석 (10820)
    // 문자열 N개가 주어진다. 
    // 이 때 문자열에 포함되는 소문자, 대문자, 숫자, 공백의 갯수를 구하는 프로그램을 작성하시오
    // 1<=N<=100
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    
    std::string str;
    while(getline(std::cin,str)){

        if(str.length()==0){
            break;
        }
        int a=0,b=0,c=0,d=0;

        for(int j=0; j<str.length();j++){
            if(str[j]>='a' && str[j]<='z'){
                a++;
            }else if(str[j]>='A' && str[j]<='Z'){
                b++;
            }else if(str[j]>='0' && str[j]<='9'){
                c++;
            }else if(str[j]==' '){
                d++;
            }
        }
        std::cout<<a<<" "<<b<<" "<<c<<" "<<d<<'\n';
    }

    return 0;
}