//将分钟数转换为小时和分钟
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int min,h,m;
    printf("请输入分钟数：\n");
    scanf("%d",&min);
    h=min/60;
    m=min%60;
    printf("转换为：%d小时%d分钟\n",h,m);
    return 0;
}
