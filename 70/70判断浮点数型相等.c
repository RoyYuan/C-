#include <stdio.h>
#include <stdlib.h>
int main()
{
	double a,b;
    scanf("%lf %lf",&a,&b);
    if (a-b<=0.00000001 && b-a<=0.00000001)
		printf("yes");
    else
		printf("no");
	system("pause");
	return 0;
}
