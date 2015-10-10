#include <stdio.h>
#include <stdlib.h>

int btd(long long int a)
{
    int b=0,m=1;
    while(a!=0)
    {
        b+=(a%10)*m;
        m*=2;
        a/=10;
    }
    return b;
}

int main()
{
    long long int n,i,s=0,a=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a);
        a=btd(a);
        s+=a;
    }
    printf("%lld",s);
    return 0;
}
