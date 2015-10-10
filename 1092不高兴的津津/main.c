#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[7][2]={0},i,t=0,s,m=0;
    for(i=0;i<7;i++)
    {
        scanf("%d %d",&x[i][0],&x[i][1]);
        s=x[i][0]+x[i][1];
        if(s>t)
        {
            t=s;
            m=i+1;
        }
    }
    if(t>8)
        printf("%d",m);
    else
        printf("0");
    return 0;
}
