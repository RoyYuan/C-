#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[10]={0},t,n=0,i;
    for(i=0;i<10;i++)
        scanf("%d",&x[i]);
    scanf("%d",&t);
    t+=30;
    for(i=0;i<10;i++)
        if(x[i]<=t)
            n++;
    printf("%d",n);
    return 0;
}
