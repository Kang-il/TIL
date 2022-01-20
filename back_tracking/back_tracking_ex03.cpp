#include <iostream>
#include <cstring>
#include <tuple>
using namespace std;

int board[10][10];
bool row[10][10];
bool col[10][10];
bool square[10][10];
bool domino[10][10];
int N=9;
int D[2][2]{{0,1},{1,0}};

pair<int,int> convert(string s){
    return make_pair(s[0]-'A',s[1]-'1');
}

int find_square(int x,int y){
    return (x/3)*3 + (y/3);
}

bool can (int x, int y, int num){
    return row[x][num] == false && col[y][num] == false && square[find_square(x,y)][num]==false;
}

void check(int x, int y, int num, bool what){
    row[x][num]=what;
    col[y][num]=what;
    square[find_square(x,y)][num]=what;
}

bool check_range(int x, int y){
    return 0 <= x && x<N && 0<=y && y < N;
}

bool dfs(int cnt){
    if(cnt==81){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<board[i][j];
            }
            cout<<'\n';
        }
        return true;
    }
    int x=cnt/N;
    int y=cnt%N;
    if(board[x][y]!=0){
        return dfs(cnt+1);
    }else{
        for(int i=0;i<2;i++){
            int nx=x+D[i][0];
            int ny=y+D[i][1];
            if(!check_range(nx,ny)) continue;
            if(board[nx][ny]!=0) continue;
            for(int i=1;i<=9;i++){
                for(int j=1;j<=9;j++){
                    if(i==j) continue;
                    if(domino[i][j]) continue;
                    if(can(x,y,i) && can(nx,ny,j)){
                        check(x,y,i,true);
                        check(nx,ny,j,true);
                        domino[i][j]=domino[j][i]=true;
                        board[x][y]=i;
                        board[nx][ny]=j;
                        if(dfs(cnt+1)){
                            return true;
                        }
                        check(x,y,i,false);
                        check(nx,ny,j,false);
                        domino[i][j]=domino[j][i]=false;
                        board[x][y]=0;
                        board[nx][ny]=0;
                    }
                }
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //(4574)
    // 스도미노쿠
    // 스도쿠가 세계적으로 유행이 된 이후에, 비슷한 퍼즐이 매우 많이 나왔다. 
    // 게임 매거진 2009년 7월호에는 스도쿠와 도미노를 혼합한 게임인 스도미노쿠가 소개되었다. 
    // 이 퍼즐은 스도쿠 규칙을 따른다. 
    // 스도쿠는 9×9 크기의 그리드를 1부터 9까지 숫자를 이용해서 채워야 한다. 
    // 스도쿠는 다음과 같은 조건을 만족하게 숫자를 채워야 한다.

    // 1. 각 행에는 1부터 9까지 숫자가 하나씩 있어야 한다.
    // 2. 각 열에는 1부터 9까지 숫자가 하나씩 있어야 한다.
    // 3. 3×3크기의 정사각형에는 1부터 9가지 숫자가 하나씩 있어야 한다.
    // 스도미노쿠의 그리드에는 1부터 9까지 숫자가 쓰여져 있고, 나머지 72칸은 도미노 타일 36개로 채워야 한다. 
    // 도미노 타일은 1부터 9까지 서로 다른 숫자의 가능한 쌍이 모두 포함되어 있다. 
    // (1+2, 1+3, 1+4, 1+5, 1+6, 1+7, 1+8, 1+9, 2+3, 2+4, 2+5, ...) 1+2와 2+1은 같은 타일이기 때문에, 
    // 따로 구분하지 않는다. 도미노 타일은 회전 시킬 수 있다. 
    // 또, 3×3 크기의 정사각형의 경계에 걸쳐서 놓여질 수도 있다.

    // 입력은 여러 개의 테스트 케이스로 이루어져 있다. 
    // 각 테스트 케이스의 첫째 줄에는 채워져 있는 도미노의 개수 N이 주어진다. (10 ≤ N ≤ 35) 
    // 다음 N개 줄에는 도미노 하나를 나타내는 U LU V LV가 주어진다. 
    // U는 도미노에 쓰여 있는 한 숫자이고, LU는 길이가 2인 문자열로 U의 위치를 나타낸다. 
    // V와 LV는 도미노에 쓰여 있는 다른 숫자를 나타낸다. 
    // 도미노의 위치는 문제에 나와있는 그림을 참고한다. 입력으로 주어지는 도미노의 각 숫자 위치는 항상 인접해 있다.

    // N개의 도미노의 정보가 주어진 다음 줄에는 채워져 있는 숫자의 위치가 1부터 9까지 차례대로 주어진다. 
    // 위치는 도미노의 위치를 나타낸 방법과 같은 방법으로 주어진다.
    // 모든 도미노와 숫자가 겹치는 경우는 없다.
    // 입력의 마지막 줄에는 0이 하나 주어진다.

    int stage=1;
    while(true){
        memset(row,false,sizeof(row));
        memset(col,false,sizeof(col));
        memset(square,false,sizeof(square));
        memset(domino,false,sizeof(domino));
        memset(board,0,sizeof(board));

        int M;
        cin>>M;
        if(M==0) break;

        for(int i=0;i<M;i++){
            int N1,N2;
            string s1,s2;
            cin>>N1>>s1>>N2>>s2;
            int x1,y1,x2,y2;
            tie(x1,y1)=convert(s1);
            tie(x2,y2)=convert(s2);
            board[x1][y1]=N1;
            board[x2][y2]=N2;
            domino[N1][N2]=domino[N2][N1]=true;
            check(x1,y1,N1,true);
            check(x2,y2,N2,true);
        }

        for(int i=1;i<=9;i++){
            string s;
            cin>>s;
            int x,y;
            tie(x,y)=convert(s);
            board[x][y]=i;
            check(x,y,i,true);
        }

        cout<<"Puzzle "<<stage<<'\n';
        dfs(0);
        stage++;
    }
    return 0;
}