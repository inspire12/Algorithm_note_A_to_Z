#define _CRT_SECURE_NO_WARNINGS // visual

#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>

using namespace std;

#define MEMSET(x, WITH) memset(x, (WITH), sizeof(x))
#define FOR(i, E) for(int i=0; i<(E); i++)
#define SCAN(n,k) scanf("%d%d",&n,&k)
typedef long long ll;
//const ll MOD = 100000000000007;
//const double PI = atan(1) *4;

int d[101][10001], v[101], w[101];
int main(){
  int n, k;
  SCAN(n,k);
  FOR(i,n){
    SCAN(v[i],w[i]);
  }
  for(int i=1; i<=n; i++){
    for(int j=0; j<=k; j++){
      if(j < w[i]){
        d[i][j] = d[i-1][j];
      }else if(d[i-1][j-w[i]] + v[i] > d[i-1][j]){
        d[i][j] = d[i-1][j- w[i]] + v[i];
      }else{
        d[i][j] = d[i-1][j];
      }
    }
  }
  int ans = 0;
  for(int i=0; i<=k; i++){
    if(ans < d[n][i]){
      ans = d[n][i];
    }
  }
  printf("%d\n", ans);
  return 0;
}
