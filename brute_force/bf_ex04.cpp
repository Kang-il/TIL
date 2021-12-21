#include <iostream>
#include <vector>

bool broken[10];
int possible(int c){
    if(c==0){
        return broken[c] ? 0 : 1;
    }
    int len=0;
    while(c>0){
        if(broken[c%10]) return 0;
        len++;
        c/=10;
    }
    return len;
}
int main(){
    //(1107)
    // TV채널을 돌리려고 했지만, 버튼을 너무 세게 누르는 바람에 일부 숫자 버튼이 고장났다.
    // 리모컨 버튼 :: 0 - 9 , + , - 가 있다.
    // + 버튼을 누를 경우 채널에서 +1된 채널로 이동하고, - 를 누르면 -1된 채널로 이동한다.
    // 채널 0에서 -를 누른 경우 채널이 변하지 않고, 채널은 무한대 만큼 있다.
    // 지금 이동하려는 채널은 N이다.
    // 채널 N으로 이동하기 위해 버튼을 최소 몇 번을 눌러야 하는지 구하는 프로그램을 작성하시오
    // 수빈이가 보는 채널은 100번이다.

    // 첫째 줄에 N이 주어진다 0 <= N < 500000
    // 둘째 줄에는 고장난 버튼의 개수가 주어진다 (0 <= M <= 10)
    // 고장난 버튼이 있는 경우 셋째 줄에는 고장난 버튼이 주어지며, 같은 버튼이 여러 번 주어지는 경우는 없다.

    int N;
    int M;
    std::cin>>N;
    std::cin>>M;

    for(int i=0;i<M;i++){
        int tmp;
        std::cin>>tmp;
        broken[tmp]=true;
    }

   int ans=std::abs(N-100);
    //ans 가 0이라면 가고자 하는 채널이 100이라 이동 할 필요 없음
   if(ans==0){
       //바로 0인 ans 를 출력 후 프로그램을 종료 해 준다.
       std::cout<<ans<<'\n';
       //끝내기
       return 0;
   }

   for(int i=0;i<=1000000;i++){
       int c=i;
       int len=possible(c);
       if(len>0){
           int press=std::abs(c-N);
           if(ans>press+len) ans=press+len;
       }
   }
   std::cout<<ans<<'\n';
    
    return 0;
}