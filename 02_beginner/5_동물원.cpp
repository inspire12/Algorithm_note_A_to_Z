#include <stdio.h>
#include <iostream>
/*
icpc.me/1309
동물원 , dp  하지만 몰라도 풀 방법 있음
*/
using namespace std;

long long int emptyZoo[1000003];
long long int leftZoo[1000003];
long long int rightZoo[1000003];

int main(){
  int N; scanf("%d",&N);
  emptyZoo[1] = 1;
  leftZoo[1] = 1;
  rightZoo[1] = 1;
  for(int i=2;i<=N; i++){
    emptyZoo[i] = rightZoo[i-1]+leftZoo[i-1]+emptyZoo[i-1];
    leftZoo[i] = rightZoo[i-1] + emptyZoo[i-1];
    rightZoo[i] = leftZoo[i-1] + emptyZoo[i-1];
    emptyZoo[i]%=9901;
    leftZoo[i]%=9901;
    rightZoo[i]%=9901;
  }
  printf("%lld",(emptyZoo[N]+leftZoo[N]+rightZoo[N])%9901);
}

/*
int f(int n){
  dp[n] =  f(n-1)*2 + f(n-2);
}
int main(){

}
*/
