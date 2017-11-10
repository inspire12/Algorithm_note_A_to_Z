
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
  int height = 6, width = 8;
  int **pArr1;
  pArr1 = (int**) malloc(sizeof(int*)*height);
  for(int i=0; i<height; i++){
    pArr1[i] = (int*) malloc(sizeof(int)*width);
  }
  cout << pArr1[2][3] << endl;
  for(int i=0; i<height; i++){
    free(pArr1[i]);
  }
  free(pArr1);
  pArr1[2][3] = 3;
  cout << pArr1[2][3] << endl;

  int *pArr2;
  pArr2 = (int*) calloc(width,sizeof(int));
  cout << pArr2[2] <<endl;

  free(pArr1[0]);
  free(pArr1);

}
/* int *pi; pi = 10; ->오류/ 할당할 때 값을 매겨야한다.
 int * pi = 10 pi라는 주소가 가리키는 메모리에 10을 할당한다. */
//http://mattlee.tistory.com/28
//https://www.joinc.co.kr/w/Site/C/Documents/PointerGuide
