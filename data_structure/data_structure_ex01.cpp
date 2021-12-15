#include <iostream>
#include <string>

int count[26];
int main(){
    //10808
    // 알파벳 소문자로만 이루어진 단어S가 주어진다. 각 알파벳이 단어에 몇 개가 
    // 포함되어있는지 구하는 프로그램을 작성하십시오.
    // 첫 째줄에 단어 S가 주어진다. 단어의 길이는 100 을 넘지 않으며, 알파벳 소문자로만 이루어져있다.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string str;
    getline(std::cin,str);

    for(char c : str){
        count[c-'a']++;
    }
    
    for(int i=0;i<26;i++){
        std::cout<<count[i];
        if(i<25){
            std::cout<<' ';
        }
    }

    std::cout<<'\n';

    return 0;
}