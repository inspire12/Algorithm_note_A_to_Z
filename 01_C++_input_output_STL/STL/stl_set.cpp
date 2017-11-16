#include <iostream>
#include <utility> //pair
#include <set>
#include <string>
#include <algorithm> //sort
/*
중복되지 않게
정렬되서 저장 / map과 동일하지만 key만 저장하고 key에 대해 정렬한 게 set

set<T> 변수명
set<T>::iterator 번수명
set<T>::reverse_iterator 변수명
set<T>::size_type 변수명
-----메소드
.insert(v)  **  -->리턴은 bool pair
.insert(a,b) 반복자 구간 [a,b)의 원소를 삽입
.begin()
.end()
.find()
.low_bound()
.swap()
*/

//#include <utility> // <algorithm> 안에 있어 --> pair
using namespace std;

void testSet();
void printSet(set<int> &s);
void printSet(set<string> &s);
void ex_problem_using_set();
void testLowerBound();
int main(){
  testSet();
  ex_problem_using_set();
}
void testSet(){
  set<int> s;
  pair<set<int>::iterator, bool> pr;
  pr = s.insert(50);
  s.insert(50);
  cout << s.size() <<endl;
  printSet(s);
}

void printSet(set<int> &s){
  for(auto i = s.begin(); i!=s.end(); i++){
    cout << *i << " ";
  }
}
void printSet(set<string> &s){
  for(auto i = s.begin(); i!=s.end(); i++){
    cout << *i << " ";
  }
  cout << endl;
}

void ex_problem_using_set(){
  string input = "abcd"; // ab ba bad ad a b
  int answer = 0;
  set<string> s;
  string tmp;
  for(int i=0; i<input.size(); i++){
    tmp =""; tmp+=input.at(i);
    //string tmp =input.substr(i,1);
    s.insert(tmp);
  }

  for(int i=1; i<input.size(); i++){
    for(int j=i-1; j>=0; j--){
        tmp = "";
        tmp += input.substr(j,i-j+1);  // 함수 원형 string substr (size_t pos = 0, size_t len = npos) const;
        //if(j==0) tmp +=input.at(i);
        // cout << input.at(j);
        // cout << input.substr(j+1, i);
        // cout <<input.substr(j+1,i).find(input.at(j))<< endl;
        if(input.substr(j+1,i).find(input.at(j)) != std::string::npos) break;
        // cout << tmp << " "<<j<<i<<endl;
        s.insert(tmp);
    }
  }
  printSet(s);
  cout<<s.size()<<endl;
}
