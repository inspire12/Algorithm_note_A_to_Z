/*

*/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int memo[4003];
int memo2[5000003];
int maxV = -1, minV = 4002;
long long int sum = 0;

int main(){
  int n; cin >> n; int tmp;
  for(int i=0; i<n; i++){
    cin >> tmp;
    if(maxV < tmp) maxV = tmp;
    if(minV > tmp) minV = tmp;
    memo[tmp]++;
    sum += tmp;
  }
  int avg = sum / n;
  int mid = 0;
  int freq;
  int rang = maxV - minV;
  int ntmp = n;
  for(int i=0; i<4002; i++){
    if(ntmp <= n/2) {mid = memo[i];break;}
    if(memo[i]>0)ntmp -= memo[i];
  }
  for(int i=0; i<4002; i++){

  }
  printf("%d\n%d\n%d\n%d\n",avg,mid,frq,rang);
}
