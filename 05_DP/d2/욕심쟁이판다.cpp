/*
  욕심쟁이 판다 icpc.me/1937
*/
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int bamboo[504][504];
int dp[504][504];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int N,maxV =0 ;

void dfsMap(int x, int y){
    int nextX,nextY;
    int value=0;
    for(int i=0;i<4;i++)
    {
        nextX=x+dx[i];
        nextY=y+dy[i];

        if(nextX>=N || nextX<0 || nextY>=N || nextY<0)
            continue;

        if(bamboo[nextX][nextY] < bamboo[x][y])
        {
            if(dp[nextX][nextY]==0)
                dfsMap(nextX,nextY);
            if(value<dp[nextX][nextY])
                value=dp[nextX][nextY];
        }
    }
    dp[x][y] = value+1;
    if(maxV < dp[x][y]) maxV=dp[x][y];
}
int print(){
  for(int i =0; i<N; i++){for(int j=0; j<N; j++){cout<<dp[i][j];}cout<<endl;}
}

int main(){
  cin >> N;
  //memeset(bamboo, sizeof(bamboo), 1);
  for(int i=0; i < N; i++){
    for(int j=0; j < N; j++){
      scanf("%d",&bamboo[i][j]);
      //dp[i][j] = 0;
    }
  }
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(dp[i][j] == 0){
       dfsMap(i,j);
    //   print(); cout<<i <<" "<<j << endl;
      }
    }
  }

  if(maxV == 0 ) maxV = 1;
  cout << maxV;
}
