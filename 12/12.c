#include <stdio.h>
#include <stdlib.h>
int main()
{
	char a;
    printf("请输入一个字符\n");
    scanf("%c",&a);
    printf("你刚才输入的字符的下一个字符是%c\n",a+1);
	system("pause");
	return 0;
}
