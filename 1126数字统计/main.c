#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,m,n,s=0,y;
    scanf("%d %d",&m,&n);
    for(i=m;i<=n;i++)
    {
        y=i;
        while(y>0)
        {
            if(y%10==2)
            {
                s++;
            }
            y/=10;
        }
    }
    printf("%d",s);
    return 0;
}
