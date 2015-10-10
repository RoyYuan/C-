#include <stdio.h>
#include <stdlib.h>

int main()
{
    int l,r,i,j,s,max=0;
    scanf("%d%d",&l,&r);
    for(i=l;i<=r;i++)
    {
        for(j=i;j<=r;j++)
        {
            s=i^j;
            max=max>s?max:s;
        }
    }
    printf("%d\n",max);
    return 0;
}
