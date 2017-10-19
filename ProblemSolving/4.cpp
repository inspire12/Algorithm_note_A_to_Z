#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
/*
2   [ "(())", "()()" ]
3   [ "((()))", "(()())", "(())()", "()(())", "()()()" ]
*/
int n = 2;
int makePatheness(int nn, int kk, string out){
  if(nn==n && kk==n){
    cout << out << endl;
    return 0;
  }
  else if(nn>=n && kk>=n){
    return 0;
  }
  if(nn<=n && kk<=n){
    if(nn >= kk)makePatheness(nn+1, kk, out+"(");
    makePatheness(nn, kk+1, out +")");
  }
}
int main(){
  // n 은 괄호 개수, k는 짝이 맞는 개수
  makePatheness(1,0,"(");
}
