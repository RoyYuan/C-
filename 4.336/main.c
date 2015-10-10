//计算出租车费
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float s,money;
    printf("请输入出租车行驶的里程数：\n");
    scanf("%f",&s);
    if(s<3)
    {
        money=7;
    }
    else
    {
        if(s<8)
        {
            money=7+1.7*(int)(s-2);
        }
        else
        {
            money=15.5+2*(int)(s-7);
        }
    }
    printf("应付金额为：%.2f元",money);
    return 0;
}
