/*
icpc.me/110000
 기본적인 스케쥴링 문제
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdio.h>
using namespace std;
int resist[200002];
vector<pair<int, int> > input;
int main(){
  int N; scanf("%d",&N);
  int a, b;
  for(int i=0; i<N; i++){
    scanf("%d%d",&a,&b);
    input.push_back(make_pair(a,b));
  }
  sort(input.begin(), input.end());
  int k = 0;
  resist[k] = input[0].second; //제한
  for(int i=1; i<N; i++){
    bool isClas = true;
    for(int j = k; j >=0 ; j--){
      if(resist[j] <= input[i].first){ // 가능하면
        resist[j] = input[i].second;
        isClas = false;
        break;
      }
    }
    if(isClas){
      k++;
      resist[k] = input[i].second;
    }
  }
  cout << k+1;
}
