#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;

int main(){
    // Upper & Lower Bound (상한과 하한)

    // 어떤 수열 A가 있을 때 
    // num의 상한은 크거나 같은 수, 하한은 작거나 같은 수를 의미한다.
    // 보통 구현 시 아래와 같은 의미로 사용한다
    // 상한 :: 큰 수 중 첫 번째 수
    // 하한 :: 작은 수 중 첫 번째 수
    vector<int> A(MAX);
    for(int i = 0 ; i<MAX ; i++) A[i] = i+1;

    int num=40;

    int left = 0;
    int right = MAX-1;
    int lower_bound=0;

    // lower bound 도출 구현
    while(left<=right){
        int mid = (left+right) / 2;
        if(A[mid] == num){
            lower_bound = mid;
            //같아도 가장 왼쪽을 구하기 위해서
            right = mid-1;
        }else if(A[mid]>num){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }

    // upper bound 도출 구현
    left=0;
    right=MAX-1;
    int upper_bound=0;
    while(left<=right){
        int mid = (left+right) / 2;
        if(A[mid]==num){
            upper_bound=mid+1;
            //같아도 가장 오른쪽을 구하기 위해서
            left=mid+1;
        }else if(A[mid] > num){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }

    cout<<"upper_bound\n";
    cout<<upper_bound<<'\n';
    cout<<"lower_bound\n";
    cout<<lower_bound<<'\n';
    cout<<"A수열에서 num의 개수\n";
    cout<< upper_bound-lower_bound <<" 개"<<'\n';
    
    return 0;
}