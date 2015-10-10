//简单计算器
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    char c;
    printf("请依次输入两个数以及运算符：\n");
    scanf("%d %d %c",&a,&b,&c);
    if(c=='+')
    {
        printf("%d %c %d = %d\n",a,c,b,a+b);
    }
    else
    {
        if(c=='-')
        {
            printf("%d %c %d = %d\n",a,c,b,a-b);
        }
        else
        {
            if(c=='*')
            {
                printf("%d %c %d = %d\n",a,c,b,a*b);
            }
            else
            {
                printf("%d %c %d = %d\n",a,c,b,a/b);
            }
        }
    }
    return 0;
}
