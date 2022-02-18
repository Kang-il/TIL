#include <iostream>
using namespace std;
int A[1000];
int main(){
    // Binary Search (이분탑색)
    // 정렬된 리스트의 값을 빠르게 찾는 방법

    for(int i=0;i<1000;i++){
        A[i]=i+1;
    }
    //찾고자 하는 수
    int x=50;
    //왼쪽 탐색범위
    int left=0;
    //오른쪽 탐색범위
    int right=999;
    // 찾고자 하는 수의 위치 저장 변수
    int position=-1;

    while(left<=right){
        // 가운데 도출
        int mid= (left+right) / 2 ;
        // 가운데가 찾고자 하는 수라면
        // 위치저장 후 break;
        if(A[mid]==x){
            position=mid;
            break;
        // A[mid]수가 찾고자 하는 수보다 큰 경우
        // A[mid]를 포함하여 그 오른쪽에 있는 수는 탐색할 필요가 없다
        // 이분탐색의 대상이 되는 배열은 정렬이 되어있다는 전제조건이 있기 때문.
        }else if(A[mid] > x){
            right=mid-1;
        // A[mid] 수가 찾고자 하는 수보다 작은 경우
        // A[mid]를 포함하여 그 왼쪽에 있는 수는 탐색할 필요가 없다.
        // 이유는 위와 같다.
        }else{
            left=mid+1;
        }
    }
    // 수가 포함되어있다면 해당 위치 출력
    // 수가 없다면 -1을 출력.
    cout<<position<<'\n';
    return 0;
}