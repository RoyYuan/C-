//从键盘上输入三个值，求其中最大值
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[3],t=0,i;
    printf("请输入三个数：\n");
    for(i=0;i<3;i++)
    {
        scanf("%d",&x[i]);
        if(x[i]>t)
        {
            t=x[i];
        }
    }
    printf("其中最大的数是：%d",t);
    return 0;
}
