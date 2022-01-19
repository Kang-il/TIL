  #include <iostream>
  using namespace std;

  int board[10][10];
  //행에 해당 숫자가 있는지 체크하는 배열
  bool row_check[10][10];
  //열에 해당 숫자가 있는지 체크하는 배열
  bool col_check[10][10];
  //작은 정사각 구간에 숫자가 있는지 체크하는 배열
  bool square_check[10][10];
  int N=9;
  //작은 정사각 구간(방번호) 구하는 메서드
  int square(int x, int y){
      return (x/3)*3+(y/3);
  }
  bool go(int z){
      if(z==81){
          for(int i=0;i<N;i++){
              for(int j=0;j<N;j++){
                  cout<<board[i][j]<<' ';
              }
              cout<<'\n';
          }
          return true;
      }
    int x=z/N; //x좌표 
    int y=z%N; //y좌표

    if(board[x][y]!=0){
        return go(z+1);
    } else{
        for(int i=1;i<=N;i++){
            if(row_check[x][i]==false && col_check[y][i]==false && square_check[square(x,y)][i]==false){
                row_check[x][i]=col_check[y][i]=square_check[square(x,y)][i]=true;
                board[x][y]=i;
                if(go(z+1)){
                    return true;
                }
                board[x][y]=0;
                row_check[x][i]=col_check[y][i]=square_check[square(x,y)][i]=false;
            }
        }
    }
    return false;
  }
  int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);
      //(2580)
      //스도쿠
      // 이 게임은 아래 그림과 같이 가로, 세로 각각 9개씩 총 81개의 작은 칸으로 이루어진 
      // 정사각형 판 위에서 이뤄지는데, 게임 시작 전 일부 칸에는 1부터 9까지의 숫자 중 하나가 쓰여 있다.
      // 나머지 빈 칸을 채우는 방식은 다음과 같다.

      // 각각의 가로줄과 세로줄에는 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
      // 굵은 선으로 구분되어 있는 3x3 정사각형 안에도 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
      // 게임 시작 전 스도쿠 판에 쓰여 있는 숫자들의 정보가 주어질 때 모든 빈 칸이 채워진 최종 모습을 출력하는 프로그램을 작성하시오.

      for(int i=0;i<N;i++){
          for(int j=0;j<N;j++){
              cin>>board[i][j];
              // 입력값이 0이 아닌경우 
              // 해당 행 열 작은 정사각 구간에 숫자가 있다고 표시해준다.
              if(board[i][j]!=0){
                  row_check[i][board[i][j]]=true;
                  col_check[j][board[i][j]]=true;
                  square_check[square(i,j)][board[i][j]]=true;
              }
          }
      }
      go(0);
      return 0;
  }