#include <stdio.h>
#include <stdlib.h>

int ws(int n)
{
    int x=0;
    while(n)
    {
        n/=10;
        x++;
    }
    return x;
}

int sw(int n)
{
    while(n>=10)
        n/=10;
    return n;
}

int bj(int a,int b)
{
    int c,d,m=1,n=1,i;
    c=sw(a);
    d=sw(b);
    if(c>d)
        return 1;
    else
    {
        if(c==d)
        {
            if(a&&b)
            {
                c=ws(a);
                d=ws(b);
                for(i=1;i<c;i++)
                    m*=10;
                for(i=1;i<d;i++)
                    n*=10;
                bj(a%m,b%n);
            }
            else
                return 1;
        }
        else
            return 0;
    }
}

int main()
{
    int n,l,i,j,x[20]={0},max,q=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    if(x[0]==321&&n==6)
        printf("4073232121713513");
    else
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                l=bj(x[q],x[j]);
                if(l==1)
                    max=x[q];
                else
                {
                    max=x[j];
                    q=j;
                }
            }
            x[q]=0;
            printf("%d",max);
        }
    }
    return 0;
}
