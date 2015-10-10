#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int c;
    int n,r,i,j;
    scanf("%d %d",&n,&r);
    c=1;
    for(i=n-r+1;i<=n;i++)
    {
        c*=i;
    }
    for(j=1;j<=r;j++)
    {
        c/=j;
    }
    printf("%ld\n",c);
    return 0;
}
