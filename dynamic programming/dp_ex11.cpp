#include <iostream>

//초기 배열 값
int a[1000];
//증가 수열의 길이를 담는 배열
int d[1000];
//변화한 인덱스 값을 넣어주는 배열
int v[1000];

void go(int p){
    if(p==-1){
        return;
    }
    go(v[p]);
    std::cout<<a[p]<<' ';
}

int main(){
    //(14002)
    //가장 긴 증가하는 부분수열 4
    //LIS도 구하고 무엇이 LIS 를 만드는지
    //10 20 10 30 20 50
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin>>n;

    for(int i=0;i<n;i++){
        std::cin>>a[i];
        d[i]=1;
        v[i]=-1;
        for(int j=0 ; j<i ; j++){
            if(a[i]>a[j] && d[i]<d[j]+1){
                d[i]=d[j]+1;
                v[i]=j;
            }
        }
    }
    
    int ans=d[0];
    int p=0;
    for(int i=0;i<n;i++){
        if(ans<d[i]){
            ans=d[i];
            p=i;
        }
    }

    std::cout<< ans << '\n';
    go(p);
    std::cout<<'\n';
    return 0;
}