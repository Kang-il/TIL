#include <iostream>
#include <string>

int count[26];
int main(){
    //10809
    // 알파벳 찾기
    // 알파벳 소문자로만 이루어진 단어 S가 주어진다.
    // 각각의 알파벳에 대해서 , 단어에 포함되어 있는 경우에는 처음 등장 위치를,
    // 포함되어있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.
    //각각의 알파벳에 대해서, a가 처음 등장하는 위치, b가 처음 등장하는 위치, ... z가 처음 등장하는 위치를 공백으로 구분해서 출력한다.
    //만약, 어떤 알파벳이 단어에 포함되어 있지 않다면 -1을 출력한다. 
    //단어의 첫 번째 글자는 0번째 위치이고, 두 번째 글자는 1번째 위치이다.

    //입력  :: baekjoon
    //출력 :: 1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
    
    //1.알파벳 배열 -1로 초기화
    for(int i=0;i<26;i++){
        count[i]=-1;
    }

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::string str;
    getline(std::cin,str);

    //처음 등장하는 알파벳일 경우에만 인덱스 값을 넣어줌
    for(int i=0;i<str.length();i++){
        if(count[str[i]-'a']==-1){
            count[str[i]-'a']=i;
        }
    }

    //출력
    for(int i=0; i<26;i++){
        std::cout<<count[i];
        if(i<25){
            std::cout<<' ';
        }
    }

    std::cout<<'\n';
    return 0;
}