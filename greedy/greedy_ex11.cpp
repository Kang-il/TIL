#include <iostream>
#include <string>
using namespace std;
string str;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>str;
}
int solution(){
    int res=0;
    string tmp="";
    bool minus=false;
    for(int i=0; i<=str.length();i++){
        if(str[i]=='+' || str[i]=='-' || str[i]=='\0'){
            if(minus){
                res-=stoi(tmp);
            }else {
                res+=stoi(tmp);
            }
            tmp="";
            if(str[i]=='-') minus=true;
        }else{
            tmp+=str[i];
        }
    }
    return res;
}
int main(){
    // (1541)
    // 잃어버린 괄호
    // 세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.
    // 그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.
    // 괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

    // 첫째 줄에 식이 주어진다. 
    // 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다.
    //  그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 
    // 수는 0으로 시작할 수 있다. 입력으로 주어지는 식의 길이는 50보다 작거나 같다.
    
    input();
    cout<<solution()<<'\n';
    return 0;
}
