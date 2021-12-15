#include <iostream>
#include <vector>
#include <string>

int GCD(int a,int b){
    if(b==0){
        return a;
    }

    return GCD(b,a%b);
}
int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N=0;
    std::cin>>N;
    
    std::vector<int> nums;
    int result=0;
    while(N--){
        int tN=0;
        std::cin>>tN;

        for(int i=0;i<tN;i++){
            int num;
            std::cin>>num;
            nums.push_back(num);
        }
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                result+=GCD(nums[i],nums[j]);
            }
        }

        std::cout<<result<<'\n';
        result=0;
        nums.clear();
    }
    return 0;
}