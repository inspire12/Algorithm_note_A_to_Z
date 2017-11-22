#include <iostream>
#include <cstdio>

using namespace std;
#define lld long long int
int memo[100];

lld fibo(int n){
  if(n<=2) return memo[n] = 1;
  if(memo[n] > 0 ) return memo[n];
  return memo[n] = fibo(n-1) + fibo(n-2);
}
int main(){
  int n; cin >> n;
  fibo(n);

  cout << memo[n];
}
