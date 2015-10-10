#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,x,r,s[999]={0};
    scanf("%d %d",&n,&m);
    if(m==8||m==16||m==10)
    {
        if(m==8)
            printf("%o",n);
        else
            if(m==16)
                printf("%x",n);
            else
                printf("%d",n);
    }
    else
    {
        if(m<10)
        {
            x=n/m;
            r=n%m;
            int i=0,j;
            while(x)
            {
                s[i]=r;
                n=x;
                x=n/m;
                r=n%m;
                i++;
            }
            s[i]=n;
            for(j=i;j>=0;j--)
            {
                printf("%d",s[j]);
            }
        }
        else
        {
            x=n/m;
            r=n%m;
            int i=0,j;
            while(x)
            {
                s[i]=r;
                n=x;
                x=n/m;
                r=n%m;
                i++;
            }
            s[i]=n;
            for(j=i;j>=0;j--)
            {
                printf("%X",s[j]);
            }
        }
    }
    return 0;
}
