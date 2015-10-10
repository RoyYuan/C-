#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b,c;
    printf("这是一个由Roy用C制作的十位数以内整数的加法计算器。\n");
    printf("-----------------------------------------------------------\n");
    printf("请输入第一个加数(整数)，按回车键确认。\n");
    scanf("%d",&a);
    printf("请输入第二个加数(整数)，按回车键确认。\n");
    scanf("%d",&b);
    c=a+b;
    printf("得出的结果是：\n");
    printf("%d+%d=%d",a,b,c);
	system("pause");
	return 0;
}
