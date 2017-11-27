/*
icpc.me/1012

*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int dp[53][53];
int start[2503];
int answer = 0;
int dx[5] = {0,0,-1,1};
int dy[5] = {1,-1,0,0};
int m,n,k;

int bfs(int sx, int sy){
  queue<pair<int, int> > q;
  q.push(make_pair(sx, sy));
  while(! q.empty()){
    int cx = q.front().first;
    int cy = q.front().second;
    dp[cx][cy] = 0; q.pop();
    for(int i=0;i<4; i++){
      int nx = cx + dx[i];
      int ny = cy + dy[i];
      if((nx < 0) || (ny < 0) || (nx >= m) || (ny >= n)) continue;
      if(dp[nx][ny] > 0 ){
        q.push(make_pair(nx,ny));
      }
    }
  }
  answer ++;
}

int main(){
  int T; cin >> T;
  int x,y;
  while(T--){
    cin >> m >> n >> k;
    answer = 0;

    for(int i=0; i<k; i++){
      cin >> x >> y;
      dp[x][y] = 1;
    }

    for(int i=0; i<m; i++){ // x
      for(int j=0; j<n; j++){ // y
        if(dp[i][j] > 0){
          bfs(i,j);
        //  cout << i << j << "| ";
        }
      }
    }
    cout << answer << endl;
  }
  return 0;
}
