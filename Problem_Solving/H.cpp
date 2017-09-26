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
int a[6];

int main(){
  int n ;cin >> n;
  vector<int> input;
  int out1 = 1, out2 =1, out3 =1;

  int tmp; //two or three
  for(int i=0; i<n; i++){
    cin >> tmp;
    input.push_back(tmp);
  }

  sort(input.begin(), input.end(),greater<int>());
  a[0] = input[0] * input[1];
  if(input[n-2] < 0){
    a[1] = input[n-1] * input[n-2];
  }else{
    a[1] = -99999;
  }
  a[3] = a[1] * input[0];
  a[4] = a[0] * input[2];
  int maxV = a[0];

  for(int i=0 ; i<=4;i++){
    maxV = maxV > a[i]?maxV:a[i];
  }
  cout << maxV;
    //cout << out;
}
