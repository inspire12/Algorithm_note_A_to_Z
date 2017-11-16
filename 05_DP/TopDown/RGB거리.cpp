/*
icpc.me/1149

*/
#define inf 999999
#include <iostream>
using namespace std;
int input[1003][4];
int memo[1003][4];
int f(int cur, int color){
//  cout << cur << color <<endl;
  if(cur == 1) return memo[cur][color] = input[cur][color]; // 종료조건
  if(memo[cur][color] != inf) return memo[cur][color]; // 중복 계산을 피하는 부분
  return memo[cur][color] = input[cur][color] + min(f(cur-1, (color+1)%3),f(cur-1, (color+2)%3) );
}
int main(){
  int N; cin >> N;
  for(int i=1; i<=N; i++){
    for(int color=0; color<3; color++){
      cin >> input[i][color];
      memo[i][color] = inf;
    }
  }

  for(int color=0; color<3; color++)f(N, color);
  cout << min(memo[N][0],min(memo[N][1],memo[N][2]));
  //
  // for(int i=1; i<=N; i++){
  //   for(int color=0; color<3; color++){
  //     cout << memo[i][color] << " ";
  //   }
  //   cout << endl;
  // }
}
