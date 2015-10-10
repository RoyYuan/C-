#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,i,j,s=0,l,a,b,x[10000]={0};
    scanf("%d",&l);
    for(i=0;i<=l;i++)
        x[i]=1;
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        for(j=a;j<=b;j++)
            x[j]=0;
    }
    for(i=0;i<=l;i++)
        s+=x[i];
    printf("%d",s);
    return 0;
}
