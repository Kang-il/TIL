#include <iostream>


int GCD(int a, int b){
    if(b==0){
        return a;
    }

    return GCD(b,a%b);
}

int main(){
    std::ios_base::sync_with_stdio(false);

    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int a;
    int b;
    std::cin>>a>>b;

    int gcd=GCD(a,b);

    int lcm=a*b/gcd;

    std::cout<<gcd<<'\n'<<lcm<<'\n';
    
    return 0;
}