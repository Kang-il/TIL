#include <iostream>
#include <stack>
#include <string>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    //쇠막대기
    //쇠막대기를 아래에서 위로 겹쳐 놓고 레이저를 수직으로 발사하여 자른다
    // 쇠막대기는 자신보다 긴 쇠막대기 위에만 놓일 수 있다.
    // 쇠막대기를 다른 쇠막대기 위에 놓는 경우 완전히 포함되도록 놓되 끝점은 겹치지 않는다.
    // 쇠막대기를 자르는 레이저는 적어도 하나 존재한다.
    // 레이저는 어떤 쇠막대기의 양 끝점과도 겹치지 않는다.
    // 1.레이저는 여는괄호와 닫는 괄호의 인접한 쌍으로 표현된다.
    // 또한 모든 '()'는 반드시 레이저를 표현한다.
    // 쇠막대기는 레이저에 의해 몇 개의 조각으로 잘려지는데 
    // 위 예에서 가장위에있는 두 개의 쇠막대기는 각각 3개와 2개의 조각으로 잘려지고
    // 이와 같은 방식으로 쇠막대기들은 총 17개의 조각으로 잘려진다.


    std::string str;
    std::stack<int> stk;
    
    getline(std::cin,str);
    int idx;
    int ans=0;
    for(char ch : str){
        if(ch=='('){
            stk.push(idx);
        }else if(ch==')'){
            if(stk.top()+1==idx){
                //레이저
                stk.pop();
                std::cout<<stk.size()<<'\n';
                ans+=(int)stk.size();
            }else{
                ans+=1;
                stk.pop();
            }
        }
        idx++;
    }
    std::cout<<ans<<'\n';
    return 0;
}