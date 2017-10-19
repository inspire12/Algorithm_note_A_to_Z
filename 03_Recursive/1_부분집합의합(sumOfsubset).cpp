/*
 icpc.me/1182
 가장 기본적인 완전 탐색
*/

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int dp[10003];
int N,K;
int answer = 0;
int count =0;
int choice(int value, int check, int k){
  if(check == 1) value+=dp[k];
  if(value == K&&check){answer++;}
//  if(check==1){cout<<value <<endl; count++;}
  if(k==0) return value;
  choice(value,1,k-1);
  choice(value,0,k-1);

}
int main(){

  cin >> N >> K;
  for(int i=0;i<N;i++){
    cin >> dp[i];
  }
  choice(0,0,N);
  //choice(0,1,1,N-1);
  cout << answer; //<< count;
}
