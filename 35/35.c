#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,n;
    a=1;
    scanf("%d",&n);
    while (n>=1)
{
		a=a*n;
        n=n-1;
}
	printf("%d",a);
	system("pause");
	return 0;
}
