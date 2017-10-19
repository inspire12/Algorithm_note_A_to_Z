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
typedef long long ll;
//const ll MOD = 100000000000007;
//const double PI = atan(1) *4;

int a[1000];
int w[1000];
 // mincount, xlimit
int dpCount[1000];
int dpLimit[1000];
int n;
int minV(int a, int b){
  return a < b? a:b;
}

//a 원래
int out = 999;
int recur(int minCount, int xlimit, int i){

  if(dpLimit[i] >= xlimit &&  dpCount[i] >= minCount){
    dpLimit[i] = xlimit;
    dpCount[i] = minCount;
  }
  if(i == n){
    return 0;
  }
  if(xlimit < a[i] - w[i]){
    dpLimit[i] = recur (minCount + 1, xlimit + w[i+1], i+1 );
    dpLimit[i] = recur (minCount, a[i], i+1); //제한 영향 x
  }else if(xlimit >= a[i] -w[i] && xlimit < a[i] +w[i]){
    dpLimit[i] = recur (minCount, xlimit + w[i], i+1);
  }else{
  //  dpLimit[i] = recur (minCount+1, xlimit + w[i], i+1);
  }
}

int main(){
  cin >>n;

  for(int i=0;i<n; i++){
    cin >> a[i];
    dpCount[i] = 999;
    dpLimit[i] = 999;
  }
  for(int i=0;i<n; i++){
    cin >> w[i];
  }
  recur(0,-w[0] ,0);
  for(int i=0;i<n; i++){
    cout << dpCount[i]<<" ";
  }
  cout << endl ;
  for(int i=0;i<n; i++){
    cout << dpLimit[i] <<" ";
  }
  cout << endl;
  cout<<dpCount[n-1];
}
