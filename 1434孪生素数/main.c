#include <stdio.h>
#include <stdlib.h>

int ss(int x)
{
    int i;
    if(x==2)
        return 1;
    else
    {
        if(x%2==0)
            return 0;
        for(i=3;i*i<=x;i+=2)
            if(x%i==0)
                return 0;
        return 1;
    }
}

int main()
{
    int m,n,i,s;
    scanf("%d%d",&m,&n);
    for(i=2;i+n<=m;i++)
    {
        s=ss(i)*ss(i+n);
        if(s==1)
            printf("%d %d\n",i,i+n);
    }
    return 0;
}
