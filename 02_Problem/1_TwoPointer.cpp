/*  test input
4
 1  2  8  9
 5
-3  3  4  5  11
*/ 
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

int arr[1000][3];
void print(int n){
  FOR(i,n){
    printf("%d ",arr[i][2]);
  }
}

int main(){
  int n, m;
  scanf("%d%d",&n,&m);
  FOR(i,n){
    scanf("%d",&arr[i][0]);
  }
  FOR(i,m){
    scanf("%d",&arr[i][1]);
  }
  int p1 =0, p2 =0;

  for (int i=0; i< n+m; i++){
    if((p2 < m) && (p1 < n) && (arr[p1][0] < arr[p2][1])){
      arr[i][2] = arr[p1][0];
      ++p1;
    }else{
      arr[i][2] = arr[p2][1];
      ++p2;
    }
  }
  print(n+m);
}
