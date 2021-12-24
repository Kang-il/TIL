#include <iostream>
#include <vector>
#include <algorithm>
void printVec(std::vector<int> &vec){
    for(int i=0;i<vec.size();i++){
        std::cout<<vec[i];
        if(i!=vec.size()-1) std::cout<<' ';
    }
    std::cout<<'\n';
    return;
}
int main(){
    //(10974)
    // 모든순열
    // N이 주어졌을 때, 1부터 N까지의 수로 이루어진 순열을 사전순으로 출력하는 프로그램을 작성하시오
    // 첫째줄에 1<=N<=8이 주어진다.
    // 첫째 줄부터 N!개의 줄에 걸쳐서 모든 순열을 사전순으로 출력한다.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin>>N;
    std::vector<int> aVec(N);

    int start=1;
    for(int i=0;i<N;i++){
        aVec[i]=start++;
    }

    bool check=true;
    //최초 순열 출력
    printVec(aVec);
    while(check){
        //다음 순열이 존재한다면 다음순열로 정렬 후 출력
        if(std::next_permutation(aVec.begin(),aVec.end())){
            printVec(aVec);
        }else{
            //없다면 check 를 false 로 바꿔줘서 loop 벗어남.
            check=false;
        }
    }

    return 0;
}