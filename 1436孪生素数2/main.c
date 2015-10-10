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
    int m,n,i,j,x,y,s=0;
    scanf("%d%d",&m,&n);
    for(i=2;i+n<=m;i++)
    {
        j=i+n;
        x=ss(i);
        y=ss(j);
        if(x&&y)
        {
            printf("%d %d\n",i,j);
            s++;
        }
    }
    printf("Total Is:%d",s);
    return 0;
}
