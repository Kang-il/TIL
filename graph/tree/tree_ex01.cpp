#include <iostream>
struct Node{
    int left;
    int right;
};
Node tree[50];
//DFS 이고 출력 순서의 차이만 있을 뿐
void preorder(int node){
    if(node==-1) return;
    std::cout<<(char)(node+'A');
    preorder(tree[node].left);
    preorder(tree[node].right);
}
void inorder(int node){
    if(node==-1) return;
    inorder(tree[node].left);
    std::cout<<(char)(node+'A');
    inorder(tree[node].right);
}
void postorder(int node){
    if(node==-1)return;
    postorder(tree[node].left);
    postorder(tree[node].right);
    std::cout<<(char)(node+'A');
}
int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // (1991)
    // 트리순회
    // 이진트리를 입력받아 전위순회 (preorder traversal), 중위 순회(inorder traversal)
    // ,후위순회(postorder traversal) 한 결과를 출력하는 프로그램을 작성하시오
    // 노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며, 
    // 항상 A가 루트 노드가 된다. 자식 노드가 없는 경우에는 .으로 표현한다.
    // 노드의 개수  :: N (1<= N <=26)
    int N;
    std::cin>>N;
    for(int i=1;i<=N;i++){
        char x,y,z;
        std::cin>>x>>y>>z;
        x=x-'A';
        if(y=='.'){
            tree[x].left=-1;
        }else{
            tree[x].left=y-'A';
        }
        if(z=='.'){
            tree[x].right=-1;
        }else{
            tree[x].right=z-'A';
        }
    }
    preorder(0);
    std::cout<<'\n';
    inorder(0);
    std::cout<<'\n';
    postorder(0);
    std::cout<<'\n';
    return 0;
}