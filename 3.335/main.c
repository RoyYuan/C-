//打印用户输入的数的平方值，用浮点型表示
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x;
    printf("请输入一个数:\n");
    scanf("%f",&x);
    printf("这个数的平方是：%f",x*x);
    return 0;
}
