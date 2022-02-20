#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Quick Sort :: 평균적인 상황에서 최고의 성능이 나오는 정렬
    
    1. pivot(피벗) 고르기 -> 이를 기준으로 그보다 작은 것은 앞으로, 큰 것은 뒤로 보낸다.
    2. pivot 앞과 뒤에서 Quick Sort를 수행한다.

    최악의 경우 O(N^2)
    평균적으로 NlogN

    퀵 정렬은 다음의 단계들로 이루어진다.
    분할(Divide): 입력 배열을 피벗을 기준으로 비균등하게 2개의 부분 배열(피벗을 중심으로 왼쪽: 피벗보다 작은 요소들, 오른쪽: 피벗보다 큰 요소들)로 분할한다.
    정복(Conquer): 부분 배열을 정렬한다. 부분 배열의 크기가 충분히 작지 않으면 순환 호출 을 이용하여 다시 분할 정복 방법을 적용한다.
    결합(Combine): 정렬된 부분 배열들을 하나의 배열에 합병한다.
    
    순환 호출이 한번 진행될 때마다 최소한 하나의 원소(피벗)는 최종적으로 위치가 정해지므로, 이 알고리즘은 반드시 끝난다는 것을 보장할 수 있다.


    5 1 4 2 8 2 5 4 6 1 9 6 9 1 
*/
vector<int> A;
int choosePivot(int low, int high){
    return low + (high-low) / 2;
}

int partition(int low, int high){
    int pivotIdx=choosePivot(low,high);
    int pivotValue=A[pivotIdx];
    //일단 pivot을 맨 끝으로 이동시킨다.
    swap(A[pivotIdx],A[high]);
    int storeIdx=low;
    for(int i=low ; i<high ; i++){
        if(A[i]<pivotValue){
            swap(A[i],A[storeIdx]);
            storeIdx++;
        }
    }
    swap(A[storeIdx],A[high]);
    return storeIdx;
}

void quickSort(int low, int high){
    if(low<high){
        int pivot=partition(low,high);
        quickSort(low,pivot-1);
        quickSort(pivot+1,high);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    A.push_back(5);
    A.push_back(1);
    A.push_back(4);
    A.push_back(2);
    A.push_back(8);
    A.push_back(2);
    A.push_back(5);
    A.push_back(4);
    A.push_back(6);
    A.push_back(1);
    A.push_back(9);
    A.push_back(6);
    A.push_back(9);
    A.push_back(1);

    for(int a : A) cout<<a<<' ';
    cout<<'\n';
    quickSort(0,A.size()-1);
    for(int a : A) cout<<a<<' ';
    cout<<'\n';

    return 0;
}