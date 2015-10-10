#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,i;
    for(i=1;i<=3;i++)
    {
        scanf("%d",&m);
        if(m==123456)
        {
            printf("正确。\n");
            break;
        }
        else
        {
            if(i==3)
            {
                printf("错误，退出。\n");
                break;
            }
            printf("错误，重新输入。\n");
        }
    }
    return 0;
}
