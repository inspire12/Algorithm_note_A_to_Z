#include <iostream>
#include <cstdio>

using namespace std;

int memo[100];

int fibo(int n){
  if(n<=2) return 1;
  if(memo[n] > 0 ) memo[n];
  return memo[n] = fibo(n-1) + fibo(n-2);
}
int main(){
  int n; cin >> n;
  fibo(n);
  // for(int i=1; i<=n; i++){
  //   cout << memo[i] << " ";
  // }
  cout << memo[n];
}
