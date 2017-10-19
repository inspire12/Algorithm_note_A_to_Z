#include <iostream>

#include <vector>
#include <algorithm> //sort

//#include <utility> // <algorithm> 안에 있어 --> pair
using namespace std;
int main(){
  int n = 3;
  pair <int , int > p1[n] = {{6,2} ,{2,2}}; //이건 또 된다.
  //pair<int, int> p3 (10,20);
  // p3 = pair<int, int>(20,30);
  // p3 = make_pair(30,40);

  sort(p1,p1+n); //first 기준으로 정렬된다.

  for(int i=0; i<n;i++)
    cout << p1[i].first <<' ' ;
 // upgrade가 튜플 get<number> (튜플 변수) 로 접근 number는 상수


 /* tuple , tie 쓰는법
    auto t = make_tuple(10, 20, 30);
   int x = get<0>(t);
   int y = get<1>(t);
   int z = get<2>(t);
   cout << x << ' ' << y << ' ' << z << '\n';
   x = y = z = 0;
   tie(x,y,z) = t;
   cout << x << ' ' << y << ' ' << z << '\n';
*/
}
