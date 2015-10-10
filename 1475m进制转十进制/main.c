#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,d,i,j,x,y,s=0;
    scanf("%x%d",&n,&m);
    if(m<=10)
    {
        x=n;
        y=1;
        for(i=1;;i++)
        {
            if(x)
            {
                s+=y*(x%10);
                x/=10;
                y*=m;
            }
            else
                break;
        }
        printf("%d",s);
    }
    else
    {
        x=n;
        y=1;
        for(i=1;;i++)
        {

        }
    }
    return 0;
}
