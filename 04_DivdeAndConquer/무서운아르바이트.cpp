#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define lld long long int
lld maxV(int a, int b){
  return a > b? a:b;
}
using namespace std;
int work[100005];
int n;
lld maxW = 0;

int recur(int left, int right){
  if(right < 0 || left>=n)return 0;
  int minW =1000002;
  //find
  if(left >= right){
    maxW=maxV(maxW, work[right]);
    return 0;
  }
  int tmpL;
  bool notMin = true;
  for(int i = left; i <= right; i++){
    if(minW > work[i]){ minW = work[i]; tmpL = i; notMin = false;}
  }
  if(notMin) return 0;
  maxW = maxV(maxW, minW*(right + 1 - left));
  recur(left, tmpL-1);
  recur(tmpL+1, right);
}


int main(){
 scanf("%d",&n);
  for(int i=0; i<n; i++){
    scanf("%d",work + i);
  }
  int left = 0, right = n-1;
  recur(left, right);
  cout << maxW;
}
