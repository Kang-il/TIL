#include <iostream>

bool prime(int a){
    if(a<2){
        return false;
    }
    for(int i=2;i*i<=a;i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin>>n;
    int ans=0;
    for(int i=0 ; i<n ; i++){
        int num;
        std::cin>>num;
        if(prime(num)){
            ans+=1;
        }
    }
    std::cout<<ans<<'\n';

    return 0;
}