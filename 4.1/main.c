#include <stdio.h>
#include <stdlib.h>

int comp(const void*a,const void*b)
{
return*(int*)a-*(int*)b;
}
int main()
{
    int x[4],i;
    for(i=0;i<4;i++)
    {
        scanf("%d",&x[i]);
    }
    qsort(x,4,sizeof(int),comp);
    for(i=0;i<4;i++)
    {
        printf("%d ",x[i]);
    }
    return 0;
}
