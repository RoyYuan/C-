#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[999],m,n,i,s=0,t=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
        m=x[i]-s;
        if(m>0)
        {
            t+=6*m;
        }
        else
        {
            t-=4*m;
        }
        t+=5;
        s=x[i];
    }
    printf("%d",t);
    return 0;
}
