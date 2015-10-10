#include <stdio.h>
#include <stdlib.h>

int jsqh(int k)
{
    double n=1,s=0;
    while(s<=k)
    {
        s+=(1.0/n);
        n++;
    }
    return (int)(n-1);
}


int main()
{
    int k,n;
    scanf("%d",&k);
    n=jsqh(k);
    printf("%d",n);
    return 0;
}
