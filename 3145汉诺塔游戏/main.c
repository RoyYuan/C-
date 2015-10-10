#include <stdio.h>
#include <stdlib.h>

void move(int a,char b,char c)
{
    printf("%d from %c to %c\n",a,b,c);
}

void hanoi(int x,char a,char b,char c)
{
    if(x==1)
    {
        move(1,a,c);
    }
    else
    {
        hanoi(x-1,a,c,b);
        move(x,a,c);
        hanoi(x-1,b,a,c);
    }
}

int main()
{
    int x,n=1,i;
    scanf("%d",&x);
    for(i=1;i<x;i++)
        n=n*2+1;
    printf("%d\n",n);
    hanoi(x,'A','B','C');
    return 0;
}
