
#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct Student {
 char name[100];
 long id;
 char major[50];
 char address[200];
};

int main()
{
 struct Student st;
 struct Student* pst;

 strcpy(st.name, "철수");
 st.id =  20001;
 strcpy(st.major, "프로그래머학과");
 strcpy(st.address, "서울시 강남구");

 pst = (struct Student*) malloc(sizeof(struct Student));
 strcpy(pst->name, "영희");
 pst->id =  20021;
 strcpy((*pst).major, "식품학과");
 strcpy((*pst).address, "전주시 덕진구");

 printf("sizeof(st) = %d\n", sizeof(st));
 printf("sizeof(pst) = %d\n", sizeof(pst));

 printf("pst->name = %s\n", pst->name);
 printf("pst->id = %d\n", pst->id);
 printf("(*pst).major = %s\n", (*pst).major);
 printf("(*pst).address = %s\n", (*pst).address);

 free(pst);
 return 0;
}
