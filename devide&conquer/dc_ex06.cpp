#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> inorder;
vector<int> postorder;
// inorder의 몇 번째
vector<int> pos;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>N;
    inorder.resize(N);
    postorder.resize(N);
    pos.resize(N+1);

    for(int i=0;i<N;i++){
        cin>>inorder[i];
        // inorder 요소들의 index 정보를 저장한다.
        pos[inorder[i]]=i;
    }
    for(int i=0;i<N;i++){
        cin>>postorder[i];
    }
}

//preorder 출력 재귀함수
void solution(int in_start, int in_end, int post_start, int post_end){
    // 더 이상 분할 할 수 없는 경우 return
    if(in_start>in_end || post_start>post_end) return;

    //postorder의 끝 값이 root 값
    //pos 를 통해 inorder에서의 root 인덱스를 쉽게 구할 수 있다.
    int root=postorder[post_end];
    cout<<root<<' ';
    // root 값을 출력한다
    int p=pos[root];
    // inorder:  in_start p in_end
    // postorder: post_start post_end
    // left: p-in_start
    // right: in_end-p

    //왼쪽 자식의 수
    // root의 인덱스 - inorder의 start
    int left=p - in_start;
    int right=in_end-p;

    solution(in_start , p-1 , post_start , post_start+left-1);
    solution(p+1 , in_end , post_start+left , post_end-1);
}
int main(){
    // (2263)
    // 트리의 순회
    // n개의 정점을 갖는 이진 트리의 정점에 1부터 n까지의 번호가 중복 없이 매겨져 있다.
    // 이와 같은 이진 트리의 인오더와 포스트오더가 주어졌을 때, 프리오더를 구하는 프로그램을 작성하시오.
    // 첫째 줄에 n(1 ≤ n ≤ 100,000)이 주어진다.
    // 다음 줄에는 인오더를 나타내는 n개의 자연수가 주어지고, 
    // 그 다음 줄에는 같은 식으로 포스트오더가 주어진다.
    input();
    solution(0,N-1,0,N-1);
    cout<<'\n';
    return 0;
}