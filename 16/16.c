#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b;
    scanf("%d %d",&a,&b);
    if (a%b==0)  printf("%d��%d��Լ����\n",b,a);
    else  printf("%d����%d��Լ����\n",b,a);
	system("pause");
	return 0;
}
