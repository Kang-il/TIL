#include <iostream>
#include <algorithm>
#define MAX 10001
struct Node{
    int left;
    int right;
    int order;
    int depth;
};
int N;
int cnt[MAX];
Node tree[MAX];
int left[MAX];//각 depth 에서 가장 왼쪽의 값을 저장 std::min(left[depth],order);
int right[MAX];//각 depth에서 가장 오른쪽의 값을 저장std::max(right[depth],order);
int order=0;
void inorder(int node, int depth){
    if(node==-1) return;
    //왼쪽부터 탐색
    inorder(tree[node].left,depth+1);
    tree[node].order=++order;
    tree[node].depth=depth;
    //오른쪽 탐색
    inorder(tree[node].right,depth+1);
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // (2250)
    // 트리의 높이와 너비
    // 이진트리를 다음의 규칙에 따라 행과 열에 번호가 붙어있는 격자 모양의 틀 속에 그리려고 한다.
    // 1. 이진트리에서 같은 레벨(level)에 있는 노드는 같은 행에 위치한다
    // 2. 한 열에는 한 노드만 존재한다.
    // 3. 임의의 노드 왼쪽 부 트리(left subtree)에 있는 노드들은 해당 노드보다 왼쪽의 열에
    //    오른쪽 부 트리(right subtree)에 있는 노드들은 해당 노드보다 오른쪽 열에 위치한다.
    // 4. 노드가 배치된 가장 왼쪽열과 오른쪽 열 사이엔 아무 노드도 없이 비어있는 열은 없다.
    // 이와 같은 규칙에 따라 이진트리를 그릴 때 각 레벨의 너비는 그 레벨에 할당된 노드 중 가장
    // 오른쪽에 위치한 노드의 열 번호에서 가장 왼쪽에 위치한 노드의 열 번호를 뺀 값 더하기 1로
    // 정의한다. 트리의 레벨은 가장 위쪽에 잇는 루트 노드가 1이고 아래로 1씩 증가한다.

    // 그림 참고 :: https://www.acmicpc.net/problem/2250

    // 임의의 이진트리가 입력으로 주어질 때 너비가 가장 넓은 레벨과 그 레벨의 너비를 출력하는 프로그램을 작성하시오
    // 노드의 개수 :: N (1<= N <= 10,000)
    
    // 열 번호 순서대로 그래프를 탐색 할 수 있다. -> inorder 방식 탐색을 사용하여 각 노드에 순서를 부여한다.
    // 각 depth 별 가장 왼쪽 열의 위치 min
    // 각 depth 별 가장 오른쪽 열의 위치 max를 구해준다.
    std::cin>>N;
    for(int i=0;i<N;i++){
        int x,y,z;
        std::cin>>x>>y>>z;
        tree[x].left=y;
        tree[x].right=z;
        if(y!=-1) cnt[y]+=1;
        if(z!=-1) cnt[z]+=1;
    }
    //근 노드 잡아주기
    int root = 0;
    for(int i=1;i<=N;i++){
        if(cnt[i]==0){
            root=i;
        }
    }
    //해당 노드를 기준으로 inorder 수행
    inorder(root,1);
    int maxDepth=0;
    for(int i=1;i<=N;i++){
        int depth=tree[i].depth;
        int order=tree[i].order;
        if(left[depth]==0){
            left[depth]=order;
        }else{
            left[depth]=std::min(left[depth],order);
        }
        right[depth]=std::max(right[depth],order);
        //가장 깊은 레벨을 이용하여 그만큼 루프 돌림
        maxDepth=std::max(maxDepth,depth);
    }
    int ans=0;
    int ansLevel=0;
    for(int i=1;i<=maxDepth;i++){
        // 가장 넓은 너비를 구하고, 깊이를 저장하여 출력
        if(ans<right[i]-left[i]+1){
            ans=right[i]-left[i]+1;
            ansLevel=i;
        }
    }
    std::cout<<ansLevel<<' '<<ans<<'\n';
    return 0;
}