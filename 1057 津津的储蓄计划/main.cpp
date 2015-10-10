#include <stdio.h>

int main()
{
    int cost[13],i;
    int leave=0,save=0;
    for(i=1;i<13;i++)
    {
        scanf("%d",&cost[i]);
    }
    for(i=1;i<13;i++)
    {
        leave+=300;
        leave-=cost[i];
        if(leave<0)
        {
            printf("%d\n",-i);
            break;
        }
        save+=(leave/100);
        leave=leave%100;
    }
    if(i==13)
    {
        leave+=save*120;
        printf("%d\n",leave);
    }
    return 0;
}
