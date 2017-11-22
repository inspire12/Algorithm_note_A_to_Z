

#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
string input;
int size;
int index = -1;
int ans = 0;
int sb = 0, lb = 0;
bool isbool =true;
int count =0;
int recur(){
  //int subAnswer = 0;
  int subSum = 0;
  for(;index<size-1;){

    index++;
    char cur = input.at(index);
    int ret = 0;
    if(cur == '('){
      sb++;
      ret = recur();
      if(ret == -1) return -1;
      subSum += 2*ret;
    }else if(cur =='['){
      lb++;
      ret = recur();
      if(ret == -1) return -1;
      subSum += 3*ret;
    }else if(cur ==')'){
      sb--;if(sb<0) return -1;
      if(input.at(index-1)=='[') return -1;
      if(input.at(index-1)=='(') return 1;
      return subSum;
    }else if(cur == ']'){
      lb--;if(lb<0) return -1;
      if(input.at(index-1)=='(') return -1;
      if(input.at(index-1)=='[') return 1;
      return subSum;
    }
  }
  return subSum;
}

int main(){

//  input = "[]";
  cin >> input;
  size = input.size();

  int ans = recur();
//  cout << ans;
  if(ans == -1) {cout <<0; return 0;}
  if(sb==0 && lb ==0) cout <<ans;
  else {cout<< 0;}
}
