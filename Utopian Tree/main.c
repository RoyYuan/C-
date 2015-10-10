#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i,h;
    scanf("%d",&t);
    int a[t];
    for(i=0;i<t;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<t;i++)
    {
        h=1;
        while(a[i]>0)
        {
            h=2*h;
            h+=1;
            a[i]-=2;
        }
        if(a[i]<0)
        {
            h-=1;
        }
        printf("%d\n",h);
    }
    return 0;
}
