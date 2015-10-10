#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a;
    scanf("%d",&a);
    if (a%2==0) printf("这是一个偶数。");
    if (a%2!=0) printf("这是一个奇数。");
	system("pause");
	return 0;
}
