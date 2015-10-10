#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f=0,i,n,m,s=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        f=0;
        if(i%3==0||i%5==0)
            f=1;
        else
        {
            m=i;
            while(m!=0)
            {
                if(m%10==3||m%10==5)
                    f=1;
                m/=10;
            }
        }
        if(f==1)
            continue;
        else
            s+=i*i;
    }
    printf("%d",s);
    return 0;
}
