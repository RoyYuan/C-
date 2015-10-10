#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long long int N,i,j,x,y,z;
    int T;
    scanf("%d",&T);
    unsigned long long int n[T];
    for(i=1;i<=T;i++)
    {
        scanf("%llu",&N);
        x=(N-1)/3;
        y=(N-1)/5;
        z=y/3;
        n[i-1]=(3+3*x)*x/2;
        n[i-1]+=(5+5*y)*y/2;
        n[i-1]-=(15+15*z)*z/2;
    }
    for(i=1;i<=T;i++)
    {
        printf("%llu\n",n[i-1]);
    }
    return 0;
}
