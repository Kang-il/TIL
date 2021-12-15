
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(){
    //접미사 배열 (11656)
    // 접미사 배열은 문자열 S의 모든 접미사를 사전 순으로 정리해 놓은 배열이다.
    // ex> baekjoon -> baekjoon, aekjoon, ekjoon, kjoon, joon, oon, on, n
    // 사전 순 정의시(오름차순)-> aekjoon, baekjoon, ekjoon, joon, kjoon, n, on, oon
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string str;
    std::cin>>str;

    std::vector<std::string> vec;

    for(int i=0;i<str.length();i++){
        std::string tmp=str.substr(i,str.length());
        vec.push_back(tmp);
    }
    //총 len 개의 원소가 있는 배열 strArr을 정렬(오름차순) 해 주는 것이다.
    sort(vec.begin(),vec.end());

    for(int i=0;i<str.length();i++){
        std::cout<<vec[i]<<'\n';
    }
    return 0;
}