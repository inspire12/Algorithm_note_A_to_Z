//#include <stdio.h>

#include <cstdio>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main(){
  // 1 공백과 줄바꿈은 무시
  string s;
  getline(cin,s);
  cout << s;

  double f = 3.14159265358979;
  cout << setprecision(5) << f <<'\n';

  // 2. 입력 형식 관련 %i는 입력 형식 관련
  //https://www.acmicpc.net/problem/11816
  int x, y;
  scanf("%d %i", &x, &y);
  //printf("%d %d\n",x,y);
  // 입력 받는 갯수 조절
  scanf("%1d", &y);
   //입력은 받지만 저장하지 않어
  scanf("%d %*d", &x);

  //3. scanf return은 성공적으로 입력받은 인자 개수 (파일끝까지 입력 받는 경우 )
  //https://www.acmicpc.net/problem/10951
  int a,b;
  while(scanf("%d%d",&a,&b) == 2);


}
