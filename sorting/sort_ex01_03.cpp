#include <iostream>
#include <vector>
#include <vector>
/*
    merge sort 를 사용한 방식
*/
using namespace std;
int N;
vector<int> A;
vector<int> B;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    A.resize(N);
    B.resize(N);
    for(int i=0;i<N;i++) cin>>A[i];
}
void merge(int start, int end){
    int mid=(start+end)/2;
    int i=start;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=end){
        if(A[i]<=A[j]){
            B[k++]=A[i++];
        }else{
            B[k++]=A[j++];
        }
    }
    while(i<=mid) B[k++]=A[i++];
    while(j<=end) B[k++]=A[j++];
    for(int i=start; i<=end;i++){
        A[i]=B[i-start];
    }
}
void sort(int start, int end){
    if(start==end) return ;
    int mid=(start+end)/2;
    sort(start,mid);
    sort(mid+1,end);
    merge(start,end);
}
void solution(){
    sort(0,N-1);
    for(int i=0;i<N;i++){
        cout<<A[i]<<'\n';
    }
}
int main(){
    // (2751)
    // 수 정렬하기 2 -- merge sort 사용
    // N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
    // 첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다.
    // 둘째 줄부터 N개의 줄에는 수가 주어진다. 
    // 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

    // 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
    input();
    solution();
    return 0;
}