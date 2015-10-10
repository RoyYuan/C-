#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y=2014,m=11,d=9,n=1000;
    int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    while(n>=365)
    {
        if((y+1)%4==0)
        {
            n-=366;
            y++;
        }
        else
        {
            n-=365;
            y++;
        }
    }
    d+=n;
    while(1)
    {
        if(a[m-1]<d)
        {
            d-=a[m-1];
            m++;
            if(m==13)
            {
                m=1;
                y++;
            }
        }
        else
        {
            break;
        }
    }
    printf("%d-%02d-%02d",y,m,d);
    return 0;
}
