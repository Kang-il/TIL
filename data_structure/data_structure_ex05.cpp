#include <iostream>
#include <string>

int main(){
    //네 수
    //네 자연수 A B C D 가 주어진다.
    // 이 때 A와 B를 붙인 수와 C와 D를 붙인 수의 합을 구하는 프로그램을 작성하시오
    // 두 수 A와 B를 합치는 것은 A의 뒤에 B를 붙이는 것을 의미한다.
    // 즉 20과 30을 붙이면 2030이 된다.
    // 1 <= A B C D <= 1,000,000
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int a,b,c,d;
    std::cin >> a >> b >> c >> d;

    std::string str1=std::to_string(a)+std::to_string(b);
    std::string str2=std::to_string(c)+std::to_string(d);

    long long result=std::stoll(str1)+std::stoll(str2);

    std::cout<<result<<'\n';

    return 0;
}