#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
int ans = 0;
int N;
int board[100][100];
int abs(int m){
  return m>0? m:-m;
}
void showBoard(string a){
  cout << a<<endl;
  for(int i=0; i<N; i++){
    for( int j=0; j<N; j++){
      printf("%d ",board[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
int checkQueen(int m,int n){
  return board[m][n]==0?1:0; //퀸 범위면 있으면 0
}

int addQueen(int m, int n){
  //printf("%d%d \n",m,n);
  for(int i=0; i<N;i++){
    board[i][n]++;
  }
  for(int i=0; i<N;i++){
    board[m][i]++;
  }
  board[m][n]--;

  for(int i = 0; i<N ;i++){
    if((m+n)-i>=0&&(m+n)-i<N){
      board[i][(m+n)-i]++;
    //  printf("%d ",(m+n)-i);
    }
    if((n-m)+i>=0&&(n-m)+i<N){
      board[i][(n-m)+i]++;
    //  printf("%d ",(m-n)+i);
    }
  }
  board[m][n]--;
  board[m][n]--;
}

int delQueen(int m, int n){
  for(int i=0; i<N;i++){
    board[i][n]--;
  }
  for(int i=0; i<N;i++){
    board[m][i]--;
  }
  board[m][n]++;for(int i = 0; i<N ;i++){
    if((m+n)-i>=0&&(m+n)-i<N){
      board[i][(m+n)-i]--;
    //  printf("%d ",(m+n)-i);
    }
    if((n-m)+i>=0&&(n-m)+i<N){
      board[i][(n-m)+i]--;
    //  printf("%d ",(m-n)+i);
    }
  }
  board[m][n]++;
  board[m][n]++;
}
int countQueen(int m,int n){
  //종료 저건

  if(n==N){
  //  showBoard("end");
    ans++;
    return 1;
  }
  if(m==N){
    return 0;
  }
  //
    if(checkQueen(m,n)){
      addQueen(m,n);
    //  showBoard("");
      for(int i=0;i<N;i++){
        if(countQueen(i,n+1))break;
      }
      delQueen(m,n);
    //  showBoard("del");
    }

  return 0;
}

int main(){
  scanf("%d", &N);
  for(int i=0;i<N;i++){
      memset(board,0,15);
      countQueen(i,0);
  }
  printf("%d\n", ans );
}
