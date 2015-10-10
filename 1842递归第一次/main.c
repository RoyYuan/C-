#include <stdio.h>
#include <stdlib.h>

int f(int x)
{
    int a=0,b=0;
    if(x>=0)
        return 5;
    else
    {
        a=f(x+1);
        b=f(x+2);
        return a+b+1;
    }
}



int main()
{
    int x,y;
    scanf("%d",&x);
    y=f(x);
    printf("%d",y);
    return 0;
}
