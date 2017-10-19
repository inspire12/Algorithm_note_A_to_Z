#include <iostream>
#include <vector>
#include <algorithm> //sort
using namespace std;

void print(vector<int> v){
  for(int i=0; i<v.size(); i++)
    cout << v[i] <<" ";
  cout << endl;
}
int comp(int a, int b){
  return a<b;
}
int main(){
  int n = 3;
  vector<int> v ={1,2,3,4,5,6}; //배열처럼 쓸 수 있음
// 배열 + 링크드 리스트

// iterator 개념!  + 포인터 개념
  sort(v.begin(), v.end());
  print(v);
  sort(v.begin(), v.end(), greater<int>() );
  print(v);
  sort(v.begin(), v.end(), comp);
  print(v);

  vector<vector<int > > v2 = {{1,2,3},{2,4,5}};   //2차원 배열 하고 비슷 (python)
  cout << v2[0][1]; //
  sort(v2[0].begin(), v2[0].end());
  //sort 3번째 매개변수는 비교 함수

}
