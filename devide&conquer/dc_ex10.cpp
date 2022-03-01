#include <iostream>
#define MAX 500000
using namespace std;

int N;
int A[MAX];
int B[MAX];

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];
}

long long solution(int start, int end){
    // bubble sort를 직접 하며 문제의 답을 알아낼 경우 시간초과가 난다.
    // merge sort를 응용하여 해결한다. -- inversion 의 개수를 세는 방식.
    // 1. 배열을 반으로 나누어 해당 인덱스보다 다음 인덱스의 우선순위가 작은 지점을 탐색한다.
    // 2. 탐색하는 과정에서 merge sort 처럼 다른 배열에 값을 업데이트한다.
    //  i. 순서가 맞다면 그대로 넣어준다.
    //  ii. 순서 반전 시 반전된 길이를 결과에 더해주고 순서에 맞게 넣어준다.
    // 업데이트된 배열을 토대로 기존 배열을 갱신해 준다.
    
    //탈출조건
    if(start==end) return 0;

    //반으로 분할하여 탐색한다.
    int mid=(start+end)/2;

    long long ans=solution(start,mid)+solution(mid+1,end);
    int i=start;
    int j=mid+1;
    int k=0;
    while(i<=mid || j<=end){
        //순서대로 있는경우 그대로 추가
        if(i<=mid && (j>end || A[i]<=A[j])) B[k++]=A[i++];
        else{
            //mid 를 기준으로 왼쪽의 inversion의 개수를 파악한다.
            ans+=(long long)(mid-i+1);
            B[k++]=A[j++];
        }
        //배열을 업데이트 해준다.
        for(int i=start ; i<=end ; i++){
            A[i]=B[i-start];
        }
    }
    return ans;
}

int main(){
    // (1517)
    // 버블 소트
    // N개의 수로 이루어진 수열 A[1], A[2], …, A[N]이 있다.
    // 이 수열에 대해서 버블 소트를 수행할 때, Swap이 총 몇 번 발생하는지 알아내는 프로그램을 작성하시오.

    // 버블 소트는 서로 인접해 있는 두 수를 바꿔가며 정렬하는 방법이다.
    // 예를 들어 수열이 3 2 1 이었다고 하자.
    // 이 경우에는 인접해 있는 3, 2가 바뀌어야 하므로 2 3 1 이 된다.
    // 다음으로는 3, 1이 바뀌어야 하므로 2 1 3 이 된다.
    // 다음에는 2, 1이 바뀌어야 하므로 1 2 3 이 된다.
    // 그러면 더 이상 바꿔야 할 경우가 없으므로 정렬이 완료된다.

    // 첫째 줄에 N(1 ≤ N ≤ 500,000)이 주어진다.
    // 다음 줄에는 N개의 정수로 A[1], A[2], …, A[N]이 주어진다.
    // 각각의 A[i]는 0 ≤ |A[i]| ≤ 1,000,000,000의 범위에 들어있다.

    // 첫째 줄에 swap 횟수를 출력한다.
    input();
    cout<<solution(0,N-1)<<'\n';
    return 0;
}