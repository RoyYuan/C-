#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b,k;
    printf("请输入两个数的值：");
    scanf("%d %d",&a,&b);
    k=a;
    a=b;
    b=k;
    printf("两个数值交换后分别为：%d %d\n",a,b);
	system("pause");
	return 0;
}
