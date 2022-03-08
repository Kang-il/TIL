#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
struct INFO{
    int age,order;
    string name;
};
int N;
vector<INFO> A;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    A.resize(N);
    // 입력 시 가입 순서를 같이 마킹해 준다.
    int order=1;
    for(int i=0;i<N;i++){ 
        cin>>A[i].age>>A[i].name;
        A[i].order=order++;
    }
}
void solution(){
    // pair 이용
    sort(A.begin(),A.end(),[](const INFO &u, const INFO &v){
        return make_pair(u.age,u.order)< make_pair(v.age,v.order);
    });
    for(INFO person : A) cout<< person.age <<' '<< person.name <<'\n';
}
int main(){
    // (10814)
    // 나이순 정렬
    // 온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다.
    // 이때, 회원들을 나이가 증가하는 순으로, 
    // 나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬하는 프로그램을 작성하시오.
    input();
    solution();
    return 0;
}