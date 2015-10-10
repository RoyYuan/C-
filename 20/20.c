#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a;
    scanf("%d",&a);
    if (a%2!=0)
		printf("%d %d %d",a+1,a+2,a+3);
    else 
		printf("%d %d %d",a-1,a-2,a-3);
	system("pause");
	return 0;
}
