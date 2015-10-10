#include <stdio.h>
#include <stdlib.h>
int main()
{
	int s,a,b,c;
    scanf("%d",&s);
    a=s/100%10;
    b=s/10%10;
    c=s/1%10;
    printf("%d",a+b+c);
	system("pause");
	return 0;
}
