#include <iostream>
#include <cstring>
#include <stack>

char a[6000000];
int main(){
    //문자 커서
    scanf("%s",a);
    int n=strlen(a);
    std::stack<char>left,right;
    for(int i=0 ; i<n ; i++){
        left.push(a[i]);
    }
    int m;
    scanf("%d",m);

    while(m--){
        char what;
        scanf(" %c",&what);
        if(what=='L'){
            if(!right.empty()){
                right.push(left.top());
                left.pop();
            }
        }else if(what=='D'){
            if(!left.empty()){
                left.push(right.top());
                right.pop();
            }
        }else if(what=='B'){
            if(!left.empty()){
                left.pop();
            }
        }else if(what=='P'){
            char c;
            scanf(" %c",c);
            left.push(c);
        }
    }

    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    while(!right.empty()){
        printf("%c",right.top());
        right.pop();
    }
    printf("\n");
    return 0;
}