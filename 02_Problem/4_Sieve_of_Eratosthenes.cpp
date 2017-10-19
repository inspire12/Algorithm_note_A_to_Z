#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> arr){
  for(int i=0; i<arr.size(); i++){
    cout << arr.at(i) << " ";
  }
}
void mySort(vector<int> arr){
  vector<int> out = arr;

}

int main(){
  int n = 6;
  vector<int> arr = {6, 15,  4,  7,  3,  6,  1};
  mySort(arr);
}
