#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b;
    double c;
    scanf("%d %lf",&a,&c);
    b=round(a*c/100)*10;
    printf("%d",b);
	system("pause");
	return 0;
}
