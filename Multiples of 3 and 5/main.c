#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long long int N,i,j;
    int T;
    scanf("%llu",&T);
    unsigned long long int n[T];
    for(i=1;i<=T;i++)
    {
        n[i-1]=0;
        scanf("%llu",&N);
        for(j=1;j<N;j++)
        {
            if(j%3==0 || j%5==0)
            {
                n[i-1]+=j;
            }
        }
    }
    for(i=1;i<=T;i++)
    {
        printf("%llu\n",n[i-1]);
    }
    return 0;
}
