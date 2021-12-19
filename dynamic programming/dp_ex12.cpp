#include <iostream>

int a[100000];
int d[100000];
// 정답의 최소값은 -1000이다 :: 임의의 수열에 -1000 들만 들어있다면
int ans= -1000;
int main(){
    //(1912)
    //연속합
    //n개의 정수로 이루어진 임의의 수열이 주어진다.
    //우리는 이 중 연속된 몇개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다.
    // 단, 수는 한 개 이상 선택해야 한다.
    //ex>> 10 ,-4, 3, 1, 5, 6, -35, 12, 21, -1
    
    // 정수 범위 1<= n <= 100,000
    // 수는 -1000보다 크거나 같고 1000보다 작거나 같은 정수이다.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin>>n;

    for(int i=0;i<n;i++){
        int tmp;
        std::cin>>tmp;
        a[i]=tmp;
    }

    for(int i=0;i<n;i++){
        //선택지 :: 연속수의 다음 수가 될 것인가, 연속 수의 첫 번째 수가 될 것인가?
        // 두 가지 선택지 중 가장 큰 값을 d[i]에 넣어준다.
        d[i]=std::max(d[i-1]+a[i],a[i]);
    }

    for(int i=0;i<n;i++){
        //ans 최초값 -1000 이며 d[i]와 비교하여 둘중 큰 값을 ans 을 넣어준다.
        ans=std::max(ans,d[i]);
    }

    std::cout<<ans<<'\n';
    return 0;
}