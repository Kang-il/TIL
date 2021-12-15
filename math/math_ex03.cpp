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

    int n=0;
    std::cin>>n;
    for(int i=0;i<n;i++){
        int a=0;
        int b=0;
        std::cin>>a>>b;
        int gcd=GCD(a,b);

        std::cout<<(a*b)/gcd<<'\n';
    }
    return 0;
}