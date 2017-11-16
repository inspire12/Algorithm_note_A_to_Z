#include<stdio.h>
int main(void)
{
    int i,n;
    scanf("%d",&n);
    if(n==1) return 0;
    for(i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            printf("%d\n",i);
            n/=i;
            i--;
        }
    }
    return 0;
}
