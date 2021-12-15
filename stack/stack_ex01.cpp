#include <iostream>
#include <string>
#include <stack>
using namespace std;

//문자열 뒤집기.
int main(){
    // 최악의 경우 -- 한 개의 단어로만 이어진 문자열
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    cin.ignore();

    while(N--){
        string str;
        getline(cin,str);
        str+='\n';
        stack<char> s;
        
        for(char ch : str){
            if(ch == ' ' || ch =='\n'){
                while(!s.empty()){
                    cout<<s.top();
                    s.pop();
                }
                cout<<ch;
            }else{
                s.push(ch);
            }
        }

    }


    return 0;
}

