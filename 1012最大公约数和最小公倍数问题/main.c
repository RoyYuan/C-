#include <stdio.h>
#include <stdlib.h>

int zdgy(int x,int y)
{
    int i,s=1,min;
    min=x>y?y:x;
    for(i=1;i<=min;i++)
    {
        if(x%i==0&&y%i==0)
            s=i;
    }
    return s;
}

int zxgb(int x,int y)
{
    int i,n=1,max,min;
    max=x<y?y:x;
    min=x+y-max;
    n=0;
    for(i=1;;i++)
    {
        if((i*min)%x==0 && (i*min)%y==0)
        {
            n=i*min;
            break;
        }
    }
    return n;
}

int main()
{
    int a,b,i,j,m,n,s=0;
    scanf("%d%d",&a,&b);
    if(b%a!=0)
        printf("0\n");
    else
    {
        for(i=1;i*a<=b;i++)
        {
            for(j=1;j*a<=b;j++)
            {
                m=zdgy(i*a,j*a);
                n=zxgb(i*a,j*a);
                if(m==a&&n==b)
                    s++;
            }
        }
        printf("%d\n",s);
    }
    return 0;
}
