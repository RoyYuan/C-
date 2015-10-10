#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m[2],x[2],y[2],k,l,i;
    scanf("%d%d%d",&k,&m[0],&m[1]);
    for(i=0;i<2;i++)
    {
        if(m[i]%k!=0)
        {
            x[i]=m[i]/k;
            if(x[i]%2)
                y[i]=k-m[i]+x[i]*k+1;
            else
                y[i]=m[i]-x[i]*k;
        }
        else
        {

            x[i]=m[i]/k-1;
            if(x[i]%2)
                y[i]=1;
            else
                y[i]=k;
        }
    }
    l=abs(x[0]-x[1])+abs(y[0]-y[1]);
    printf("%d",l);
    return 0;
}
