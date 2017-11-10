#include <malloc.h>
#include <stdio.h>

void alloc(int* a){
  a = (int*) malloc(sizeof(int)*100);
}
int main(){
  int a[50];
  //alloc(a);
  a[0] = 3; //해제된 메모리 영역에 뭔가 쓰려고 할때?
  printf("%d",a[0]);
}
