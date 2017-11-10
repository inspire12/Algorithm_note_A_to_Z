

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
  vector<int> out;
  int loc;
  int size = arr.size();
  for(int i=0; i< size; i++){
    //cout << min_element(arr.begin(), arr.end()) - arr.begin();
    loc =  distance(arr.begin(), min_element(arr.begin(), arr.end()));
    out.push_back(arr.at(loc));
    arr.erase(arr.begin()+loc);
  }
  print(out);
}

int main(){
  int n = 6;
  vector<int> arr = {6, 15,  4,  7,  3,  6,  1};
  mySort(arr);
}
