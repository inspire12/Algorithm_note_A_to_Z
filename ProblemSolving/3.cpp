#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int manV(int a , int b){
  return a > b? a:b;
}
// {15,5,3,7,9,14,0} => 3
int main(){
  int road = 15;
  vector<int> arr = {15,5,3,7,9,14,0};
  int len = arr.size();
  sort(arr.begin(), arr.end());
  int max = manV(arr[0], road - arr[len-1]);

  int tmp = 0;
  for(int i=1; i<len; i++){
    tmp = (arr[i] - arr[i-1] + 1) / 2 ;
    max = manV(max, tmp);
  }
  printf("%d",max);
}
