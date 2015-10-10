#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,n,m,k,i,s,x[1000]={0};
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d%d%d",&n,&k,&m);
        if(n<=m)
            s=k;
        else
        {
            if((n*k)%m==0)
                s=((n*k)/m);
            else
                s=((n*k)/m)+1;
        }
        x[i]=s;
    }
    for(i=0;i<t;i++)
        printf("%d\n",x[i]);
    return 0;
}
