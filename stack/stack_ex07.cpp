#include <iostream>
#include <vector>
#include <stack>
int freq[1000001];
int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N=0;
    std::cin>>N;
    
    std::vector<int> a(N);
    std::vector<int> ans(N);

    for(int i=0;i<a.size();i++){
        std::cin>>a[i];
        freq[a[i]]+=1;
    }

    std::stack<int> stk;
    stk.push(0);
    for(int i=1;i<a.size();i++){
        if(stk.empty()){
            stk.push(i);
        }
        while(!stk.empty() && freq[a[stk.top()]]<freq[a[i]]){
            ans[stk.top()]=a[i];
            stk.pop();
        }
        stk.push(i);
    }

    while(!stk.empty()){
        ans[stk.top()]=-1;
        stk.pop();
    }

    for(int i=0;i<ans.size();i++){
        std::cout<<ans[i]<<' ';
    }

    std::cout<<'\n';
    
    return 0;
}