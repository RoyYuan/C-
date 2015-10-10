#include <stdio.h>
#include <stdlib.h>

void test(int x[49],int m,int n)
{
    int sum=1,i;
    for(i=1;i<49;i++)
    {
        if(i==m || i==n)
        {
            sum-=x[i-1];
            sum+=x[i-1]*x[i];
        }
        else
            sum+=x[i];
    }
    if(sum==2015)
        printf("%d\n",x[m-1]);
}

int main()
{
    int i,j,x[49];
    for(i=1;i<49;i++)
        x[i]=i+1;
    for(i=1;i<47;i++)
        for(j=i+2;j<49;j++)
            test(x,i,j);
    return 0;
}
