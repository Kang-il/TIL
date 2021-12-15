#include <iostream>

//유클리드 호제법
int GCD(int a,int b){
    if(b==0){
        return a;
    }else{
        return GCD(b,a%b);
    }
}

int GCD2(int a,int b){
    while(b!=0){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

bool prime(int n){
    if(n<2){
        return false;
    }

    for(int i=2; i<=n/2 ; i++){
        if(n%i==0){
            //소수가 아니다.
            return false;
        }
    }

    return true;
}

bool prime2(int n){
    if(n<2){
        return false;
    }
    
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }

    return true;
}

int main(){
    //(A+B)%M == ((A%M)+(B%M))%M
    //(AXB)%M == ((A%M)*(B%M))%M
    //(A-B)%M == (A%M - B%M + M) % M

    //최대공약수 GCD
    //유클리드호제법
    //GCD (a,b) a%b=r
    //GCD(a,r);

    //최소공배수 LCM
    //G=GCD(A,B)
    //LCM = (A*B)/G

    //소수
    //약수가 1과 자기자신 뿐
    //2보다 같거나 크고 N-1보다 작거나 같은 자연수로 나누어 떨어지지않는 수

    //1. 어떤수가 소수인지 아닌지 판단
    //2. N보다 작거나 같은 모든 소수 구하기


    return 0;
}