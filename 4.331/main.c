//猜猜看，固定样板数，判断大小
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int yangban=995,g;
    printf("请猜测样板数(三位数):\n");
    scanf("%d",&g);
    if(g==yangban)
    {
        printf("正确！");
    }
    else
    {
        if(g<yangban)
        {
            printf("太小！");
        }
        else
        {
            printf("太大！");
        }
    }
    return 0;
}
