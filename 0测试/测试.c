#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("这是一个测试编译器的小程序。\n");
    int a;
    a=1;
    while (a<100)
    {
        printf("%d\n",a);
        a=a+1;
    }
    system("pause");
    return 0;
}
