#include <stdio.h>
#include <stdlib.h>

int a(int*n,int x)
{
    int i;
    for(i=1;(i*2)<=x;i++)
    {
        (*n)++;
        a(n,i);
    }
    return 0;
}

int main()
{
    int x,n=1;
    scanf("%d",&x);
    a(&n,x);
    printf("%d",n);
    return 0;
}
