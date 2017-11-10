#include <stdio.h>

int *pPointer2;

void SomeFunction(){
  int nNumber;
  nNumber =15;
  pPointer2 = &nNumber;
}

int main(){
  int nNumber;
  int *pPointer ;

  nNumber = 15;
  pPointer = &nNumber;
  //pPointer = 10  -> 에러
  *pPointer = 2;
  printf("%d\n", *pPointer);
  printf("%d\n", nNumber);
  printf("----------\n");
  SomeFunction();
  printf("%d",*pPointer2); //실패해야하는데, 지역변수에 선언된건 함수가 끝나면 날아가야하니까
  // 날려도 주소값이 완전 날라가지 않는 것 같다.
  
}

//https://www.joinc.co.kr/w/Site/C/Documents/PointerGuide
