#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
    Quick Select
    정렬되지 않은 리스트에서 K번 째 작은 수를 찾는 알고리즘
    Quick sort와 같지만 한쪽만 호출

    평균적인 시간 복잡도 O(N)이나
    최악의 경우 O(N^2)
*/
vector<int> A;

int partition(int low, int high){
    int pivot=A[low];
    int i=low+1,j=high;
    while(i<=j){
        while(A[i]<=pivot && i<=high) i++;
        while(A[j]>= pivot && j>=(low+1)) j--;
        if(i<=j) swap(A[i],A[j]);
    }
    swap(A[low],A[j]);
    return j;
}

int quickSelect(int start, int end, int K){
    if(start>=end) return;
    int nth=partition(start,end);
    if(nth==K) return A[nth];
    else if(nth>K) quickSelect(start,nth-1,K);
    else if(nth<K) quickSelect(nth+1,end,K);
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

    cout<<quickSelect(0,A.size()-1,2)<<'\n';
    return 0;
}