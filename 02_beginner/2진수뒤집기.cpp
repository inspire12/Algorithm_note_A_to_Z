#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

int main(){
  int input; cin >> input;
  int ans = 0;
  while(input != 0){
    ans *= 2;
    ans += input%2;
    input>>=1;
  }
  cout << ans;
}
