#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a;
    printf("这是一个正数判断器。\n请输入一个数值");
    scanf("%d",&a);
    if (a>0)
      printf("这个数是正数。\n");
    if (a<=0)
      printf("这个数不是正数。\n");  
	system("pause");
	return 0;
}
