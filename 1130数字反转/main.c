#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long int m=0,n,l=1;
    int i,j,k=0;
    scanf("%lld",&n);
    m=abs(n);
    j=n>=0?1:0;
    while(m!=0)
    {
        m/=10;
        l*=10;
        k++;
    }
    l/=10;
    for(i=0;i<k;i++)
    {
        m+=(abs(n)%10)*l;
        n/=10;
        l/=10;
    }
    if(j==1)
        printf("%lld",m);
    else
        printf("-%lld",m);
    return 0;
}
