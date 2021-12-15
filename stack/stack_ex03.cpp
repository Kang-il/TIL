#include <iostream>
#include <stack>
#include<string>

int main(){
    std::ios_base::sync_with_stdio(false);

    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // 스택 수열
    // 1부터 N까지의 수를 스택에 넣었다가 뽑아 놓음으로 하나의 수열을 만들 수 있다.
    // push 하는 순서는 오름차순이다.
    // 임의의 수열 A가 있을 때, 스택을 이용해 수열을 만들 수 있는지 없는지 구하는 문제
    // A=[4,3,6,8,7,5,2,1]
    // ++++ -- ++ - ++ ----- 를 이용해 만들 수 있다.

    //스택에 push 되는 순서는 오름차순이다.
    //pop이 되는 순서대로 수열 A가 만들어지기 때문에 A의 첫 수부터 순서대로 만들어보면 된다.
    //m = 스택에 추가되어야 하는 수
    //A[i]=만들어야 하는 수열의 A수 
    int n;
    std::string ans;
    std::cin>>n;
    std::stack<int> s;
    int m=0;
    while(n--){
        int x;
        if(x>m){
            while(x>m){
                s.push(m++);
                ans+='+';
            }
            s.pop();
            ans+='-';
        }else{
            bool found=false;
            if(!s.empty()){
                int top=s.top();
                s.pop();
                ans+='-';
                if(x==top){
                    found=true;
                }
            }
            if(!found){
                std::cout<<"NO"<<std::endl;
                return 0;
            }
        }
    }
    for(auto x : ans){
        std::cout<<x<<'\n';
    }
    return 0;
}