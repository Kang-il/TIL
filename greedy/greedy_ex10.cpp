#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> arr;
void solution(){
    cin>>N;
    for(int i=0;i<N;i++){
        int input;
        cin>>input;
        if(arr.empty() || arr.back()<input){
            arr.push_back(input);
        }else *lower_bound(arr.begin(),arr.end(),input) = input;
    }
    cout<< arr.size()<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //(12015)
    // 가장 긴 증가하는 부분수열 2
    // 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

    // 예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 
    // 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
    // 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.
    // 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000,000)
    solution();
    return 0;
};