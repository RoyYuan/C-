//输入矩形两边，求面积
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,s;
    printf("请输入矩形的长和宽：\n",&a,&b);
    scanf("%d %d",&a,&b);
    s=a*b;
    printf("矩形的面积是：%d",s);
    return 0;
}
