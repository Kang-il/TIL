#include <iostream>
using namespace std;

int nums[20];
bool check[20*100000+10];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
     //(14225)
     // 부분수열의 합 --  비트마스크 풀이
     // 수열 S가 주어졌을 때, 수열 S의 부분수열의 합으로 나올 수 없는 
     // 가장 작은 자연수를 구하는 프로그램을 작성하시오
     // 예를 들어, S = [5, 1, 2]인 경우에 
     // 1, 2, 3(=1+2), 5, 6(=1+5), 7(=2+5), 8(=1+2+5)을 만들 수 있다. 
     // 하지만, 4는 만들 수 없기 때문에 정답은 4이다.
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>nums[i];
    }
    for(int i=0;i<(1<<N);i++){//i 범위 2^N
        int sum=0;
        for(int j=0;j<N;j++){
            if(i&(1<<j)){//포함여부 검사
                sum+=nums[j];
            }
        }
        check[sum]=true;
    }
    for(int i=0;;i++){
        if( !check[i] ) {
            cout<<i<<'\n';
            break;
        }
    }
    return 0;
}