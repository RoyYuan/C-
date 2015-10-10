#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b;
    scanf("%d %d",&a,&b);
    if (a%b==0)  printf("%d是%d的约数。\n",b,a);
    else  printf("%d不是%d的约数。\n",b,a);
	system("pause");
	return 0;
}
