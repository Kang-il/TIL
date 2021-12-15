#include <iostream>
//DPEX

//피보나치 수를 구하는 함수이다.
//함수의 깊이 2N^2 -- 재귀함수 시
//memo 활용 시 -- 모든 문제를 한 번 씩 푼다. --> 문제의 개수(N개) X 문제 1개를 푸는 사간(=함수의 시간복잡도와 같다.O(1)) --> O(N)이라고 할 수 있다.
//
int d[100];
int memo[100];

int fibonacci_top_down(int n){//재귀호출 이용 -- 스택오버플로우 주의해야 하나 - C++과 Java는 발생하는 경우가 많진 않음 -- 만약 났다면 내가 코드를 잘못 짠경우가 대부분
    //더이상 쪼갤 수 없는 수 0,1 예외처리
    if(n<=1){
        return n;
    }else{
        if(memo[n]>0){
            return memo[n];
        }
        //메모하기 
        memo[n]=fibonacci_top_down(n-1)+fibonacci_top_down(n+1);
        return memo[n];
    }
}

int fibonacci_bottom_up(int n){//반복문 사용 -- Python에서 적합한 
    d[0]=0;
    d[1]=1;
    for(int i=2;i<=n;i++){
        d[i]=d[i-1]+d[i-2];
    }
    return d[n];
}


int main(){
    //한 번 답을 구한 뒤


    //점화식
    return 0;
}