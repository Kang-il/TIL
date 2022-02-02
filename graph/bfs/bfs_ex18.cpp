#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int N;
int D[4][2]{{1,0},{-1,0},{0,1},{0,-1}};

tuple<int,int,int> bfs(vector<vector<int>> &board , int x, int y, int size){
    vector<vector<int>> dist_vec(N,vector<int>(N,-1));
    queue<pair<int,int>>q;
    vector<tuple<int,int,int>> ans;
    q.push(make_pair(x,y));
    dist_vec[x][y]=0;
    while(!q.empty()){
        tie(x,y)=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+D[i][0];
            int ny=y+D[i][1];
            //보드 범위
            if(nx<0 || ny <0 || nx>N-1 || ny>N-1) continue;
            //이미 갔던 곳.
            if(dist_vec[nx][ny]!=-1)continue;
            bool ok=false;
            bool eat=false;
            if(board[nx][ny]==0){//보드 현 위치가 비어있을 경우
                //지나가기 가능
                ok=true;
            }else if(board[nx][ny]<size){ // 보드에 있는 물고기가 상어의 크기보다 작을 경우
                //이동 가능 잡아먹기 가능
                ok=eat=true;
            }else if(board[nx][ny]==size){// 보드에 있는 물고기가 상어의 크기와 같을경우
                //지나가기만 가능
                ok=true;
            }
            if(ok){
                //지나갈 수 있으니 이동전 상어 위치에 +1 한 수를 이동위치에 넣어줌 
                dist_vec[nx][ny]=dist_vec[x][y]+1;
                q.push(make_pair(nx,ny));
                if(eat){
                    //먹을 수도 있다면 ans 에 push_back;
                    ans.push_back(make_tuple(dist_vec[nx][ny],nx,ny));
                }
            }
        }
    }
    if (ans.empty()){//비어있다면 먹을 수 있는 물고기가 없음
        return make_tuple(-1,-1,-1);
    }
    //1. 거리가 가장 가까운
    //2. 가장 위쪽
    //3. 가장 왼쪽
    // 순으로 정렬 될 것임.
    sort(ans.begin(),ans.end());
    return ans[0];
}
void solution(vector<vector<int>> &board, int x, int y){
    int ans=0;
    int eat=0;
    int size=2;
    while(true){
        int nx, ny, dist;
        //선택된 고기 먹기
        tie(dist,nx,ny)=bfs(board,x,y,size);
        if(dist==-1) break;
        ans+=dist;
        eat++;
        //먹은 후 빈공간 처리
        board[nx][ny]=0;
        //사이즈만큼 물고기를 먹었다면
        //사이즈가 커짐
        if(eat==size){
            size++;
            eat=0;
        }
        //위치 갱신
        tie(x,y)=make_pair(nx,ny);
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // (16236)
    // 아기상어
    // N×N 크기의 공간에 물고기 M마리와 아기 상어 1마리가 있다. 
    // 공간은 1×1 크기의 정사각형 칸으로 나누어져 있다. 한 칸에는 물고기가 최대 1마리 존재한다.

    // 아기 상어와 물고기는 모두 크기를 가지고 있고, 이 크기는 자연수이다.
    // 가장 처음에 아기 상어의 크기는 2이고, 아기 상어는 1초에 상하좌우로 인접한 한 칸씩 이동한다.

    // 아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다.
    // 아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다. 따라서, 크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.

    // 아기 상어가 어디로 이동할지 결정하는 방법은 아래와 같다.

    // 더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.
    // 1. 먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
    // 2. 먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
    // 3. 거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최솟값이다.
    // 4. 거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
    // 아기 상어의 이동은 1초 걸리고, 물고기를 먹는데 걸리는 시간은 없다고 가정한다. 
    // 즉, 아기 상어가 먹을 수 있는 물고기가 있는 칸으로 이동했다면, 이동과 동시에 물고기를 먹는다. 물고기를 먹으면, 그 칸은 빈 칸이 된다.

    // 아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다. 예를 들어, 크기가 2인 아기 상어는 물고기를 2마리 먹으면 크기가 3이 된다.
    // 공간의 상태가 주어졌을 때, 아기 상어가 몇 초 동안 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지 구하는 프로그램을 작성하시오.
    // 0: 빈 칸
    // 1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
    // 9: 아기 상어의 위치
    cin>>N;
    int x,y;
    vector<vector<int>> board(N,vector<int>(N,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>board[i][j];
            if(board[i][j]==9){
                board[i][j]=0;
                tie(x,y)=make_pair(i,j);
            }
        }
    }
    solution(board,x,y);
    return 0;
}