#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

pair<int,int> calc(vector<int> &a,int idx, int cur, int plus,int minus, int mul, int div){
   int N=a.size();
    if(idx==N){
        return make_pair(cur,cur);
    }
    vector<pair<int,int>> res;
    if(plus>0){
        res.push_back(calc(a,idx+1,cur+a[idx],plus-1,minus,mul,div));
    }
    if(minus>0){
        res.push_back(calc(a,idx+1,cur-a[idx],plus,minus-1,mul,div));
    }
    if(mul>0){
        res.push_back(calc(a,idx+1,cur*a[idx],plus,minus,mul-1,div));
    }
    if(div>0){
        res.push_back(calc(a,idx+1,cur/a[idx],plus,minus,mul,div-1));
    }
    
    pair<int,int> ans=res[0];
    for(auto x : res){
        if(ans.first<x.first) ans.first=x.first;
        if(ans.second>x.second) ans.second=x.second;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    //(14888)
    // 연산자 끼워넣기
    // N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다. 
    // 또, 수와 수 사이에 끼워넣을 수 있는 N-1개의 연산자가 주어진다. 
    // 연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로만 이루어져 있다.
    // 우리는 수와 수 사이에 연산자를 하나씩 넣어서, 수식을 하나 만들 수 있다. 이때, 주어진 수의 순서를 바꾸면 안 된다.
    // 예를 들어, 6개의 수로 이루어진 수열이 1, 2, 3, 4, 5, 6이고, 
    // 주어진 연산자가 덧셈(+) 2개, 뺄셈(-) 1개, 곱셈(×) 1개, 나눗셈(÷) 1개인 경우에는 총 60가지의 식을 만들 수 있다. 
    // 예를 들어, 아래와 같은 식을 만들 수 있다.
    // 1+2+3-4×5÷6
    // 1÷2+3+4-5×6
    // 1+2÷3×4-5+6
    // 1÷2×3-4+5+6
    // 식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행해야 한다. 
    // 또, 나눗셈은 정수 나눗셈으로 몫만 취한다. 음수를 양수로 나눌 때는 C++14의 기준을 따른다. 
    // 즉, 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것과 같다. 
    // 이에 따라서, 위의 식 4개의 결과를 계산해보면 아래와 같다.
    // 1+2+3-4×5÷6 = 1
    // 1÷2+3+4-5×6 = 12
    // 1+2÷3×4-5+6 = 5
    // 1÷2×3-4+5+6 = 7
    // N개의 수와 N-1개의 연산자가 주어졌을 때, 
    // 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.
    int N;
    cin>>N;

    vector<int> a(N);
    for(int i=0;i<N;i++){
        cin>>a[i];
    }

    int plus,minus,mul,div;
    cin>>plus>>minus>>mul>>div;
    auto ans = calc(a,1,a[0],plus,minus,mul,div);
    cout<<ans.first<<'\n';
    cout<<ans.second<<'\n';

    return 0;
}