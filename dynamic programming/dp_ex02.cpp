#include <iostream>

int d[1000001];

//Top_down
int go_top_down(int n){
    if(n==1){
        return 0;
    }

    if(d[n]>0) return d[n];

    d[n]=go_top_down(n-1)+1;

    if(n%2==0){
        int temp=go_top_down(n/2)+1;
        if(d[n]>temp) d[n]=temp;
    }

    if(n%3==0){
        int temp=go_top_down(n/3)+1;
        if(d[n]>temp) d[n]=temp;
    }
    return d[n];
    
}

int go_bottom_up(int n){
    d[1]=0;
    
    for(int i=2; i<=n ; i++){
        d[i]=d[i-1]+1;
        if(i%2==0 && d[i] > d[i/2]+1 ){
            d[i]=d[i/2]+1;
        }
        if(i%3==0 && d[i] > d[i/3]+1){
            d[i]=d[i/3]+1;
        }
    }
   
    return d[n];
}

int main(){
    //1463 
    //1로 만들기
    // 정수 X에서 사용할 수 있는 연산은 다음과 같이 세가지
    //1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
    //2. X가 2로 나누어 떨어지면, 2로 나눈다.
    //3. 1을 뺀다.

    //어떤 정수 N에 위와 같은 연산을 선택해서 1을 만드려고 한다. 연산에 사용하는 횟수의 최솟값을 구하는 문제.
    //ex> 8 -> 4 -> 2 -> 1
    //ex> 9 -> 3 -> 1
    
    //N을 1로 만드는 것은 작게 나누는 것.
    //10 은 3으로 나누는 것 2로 나누는것, 1을 빼는 것을 우선순위로 N을 1로 만들어 본다.
    
    //점화식의 정의
    //문제에서 구해야 하는 것 -- > N을 1로 만드는 최소 연산횟수.(목표)
    //D[N]
    //N을 작게 만들 수 있는 방법은 무엇인지?
    //N- > N/3 (1번) -> 1 (+ D[N/3])
    //1+D[N/2]
    //1+D[N-1]
    //각각중 최소값을 구할 것.
    //D[N]에 넣어주면 된다 == min(D[N/3],D[N/2],D[N-1])
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int result=0;
    int N=0;
    std::cin>>N;

    result=go_top_down(N);

    std::cout<<result<<'\n';

    return 0;
}