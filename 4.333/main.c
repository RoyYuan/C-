//假设今天周日，计算123456天后是周几
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d=123456;
    printf("假设今天是周日，123456天后是");
    switch(d%7)
    {
        case 0:printf("周日。"); break;
        case 1:printf("周一。"); break;
        case 2:printf("周二。"); break;
        case 3:printf("周三。"); break;
        case 4:printf("周四。"); break;
        case 5:printf("周五。"); break;
        case 6:printf("周六。"); break;
    }
    return 0;
}
