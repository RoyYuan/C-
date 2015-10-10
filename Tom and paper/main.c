#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    unsigned long int t,a,b,kf;
    int k;
    scanf("%d",&k);
    while(k)
    {
        scanf("%lu",&t);
        kf=sqrt(t);
        if(kf*kf==t)
            printf("%lu\n",4*kf);
        else
        {
            a=kf+1;
            b=t/a;
            while(a*b!=t)
            {
                a--;
                b=t/a;
            }
            printf("%lu\n",2*(a+b));
        }
        k--;
    }
    return 0;
}
