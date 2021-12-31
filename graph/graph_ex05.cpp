#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

struct Point{
    int x;
    int y;
    Point(int x, int y){
        this->x=x;
        this->y=y;
    }
};

int N;
int board[25][25];
bool visited[25][25];
int d[4][2]{{1,0},{-1,0},{0,1},{0,-1}};
std::vector<int> ans;

void bfs(int x, int y){
    visited[x][y]=true;
    std::queue<Point> q;
    q.push(Point(x,y));
    int cnt=1;
    while(!q.empty()){
        Point p=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=p.x+d[i][0];
            int ny=p.y+d[i][1];

            if(nx<0 || ny<0) continue;
            if(nx>N-1 || ny>N-1) continue;
            if(visited[nx][ny]) continue;
            if(board[nx][ny]==0) continue;

            visited[nx][ny]=true;
            q.push(Point(nx,ny));
            cnt++;
        }
    }
    ans.push_back(cnt);
}
int main(){
    // (2667)
    // 단지 번호붙이기.
    // 1은 집이 있는 곳
    // 0 은 집이 없는 곳을 나타낸다
    // 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고
    // 단지에 번호를 붙이려고 한다.
    // 연결되어있다는 것은 어떤집이 좌우, 혹은 아래 위로 다른 집이 있는 경우를 말한다.
    // 지도를 입력하여 단지 수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여
    // 출력하는 프로그램을 작성하시오.
    // 지도의 크기 :: N (5<=N<=25)
    std::cin>>N;
    for(int i=0;i<N;i++){
       std::string tmp;
       std::cin>>tmp;
       for(int j=0;j<N;j++){
           board[i][j]=tmp[j]-'0';
       }
    }
    int cnt=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j] && board[i][j]==1){
                bfs(i,j);
                cnt++;
            }
        }
    }
    std::sort(ans.begin(),ans.end());
    std::cout<<cnt<<'\n';
    for(int i=0;i<ans.size();i++){
        std::cout<<ans[i]<<'\n';
    }

    return 0;
}