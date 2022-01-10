#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

char alpha[256];

int calc(std::vector<std::string> &a, std::vector<char> &letters, std::vector<int> &d){
    int m=letters.size();
    int sum=0;
    for(int i=0;i<m;i++){
        alpha[letters[i]]=d[i];
    }
    for(std::string s : a){
        int now=0;
        for(char x : s){
            now=now*10+alpha[x];
        }
        sum+=now;
    }
    return sum;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    //(1339)
    // 단어수학
    // 단어 수학 문제는 N개의 단어로 이루어져 있으며, 각 단어는 알파벳 대문자로만 이루어져있다.
    // 이 때, 각 알파벳 대문자를 0부터 9까지의 숫자 중 하나로 바꿔서 N개의 수를 합하는 문제이다.
    // 같은 알파벳은 같은 숫자로 바꿔야 하며, 두 개이상의 알파벳이 같은 숫자로 바뀌어지면 안된다.
    // 예를 들어, GCF + ACDEB를 계산한다고 할 때, A = 9, B = 4, C = 8, D = 6, E = 5, F = 3, G = 7로 결정한다면, 
    // 두 수의 합은 99437이 되어서 최대가 될 것이다.
    int N;
    std::cin>>N;
    std::vector<std::string> a(N);
    std::vector<char> letters;
    for(int i=0;i<N;i++){
        std::cin>>a[i];
        for(char x: a[i]){
            letters.push_back(x);
        }
    }
    std::sort(letters.begin(),letters.end());
    letters.erase(std::unique(letters.begin(),letters.end()),letters.end());

    int M=letters.size();
    std::vector<int> d;
    for(int i=9;i>9-M;i--){
        d.push_back(i);
    }
    std::sort(d.begin(),d.end());
    int ans=0;
    do{
        int now=calc(a,letters,d);
        if(ans<now){
            ans=now;
        }
    }while(std::next_permutation(d.begin(),d.end()));
    std::cout<<ans<<'\n';
    return 0;
}