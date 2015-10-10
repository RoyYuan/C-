#include <stdio.h>
#include <stdlib.h>

int sum=0,x[13];

void f(int t)
{
    if(t!=13)
    {
        for(x[t]=0;x[t]<5;x[t]++)
            f(t+1);
    }
    else
    {
        if(x[0]+x[1]+x[2]+x[3]+x[4]+x[5]+x[6]+x[7]+x[8]+x[9]+x[10]+x[11]+x[12]==13)
            sum++;

    }
}

int main()
{
    f(0);
    printf("%d",sum);
    return 0;
}
