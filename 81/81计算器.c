#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b;
    char c;
    scanf("%d%c%d",&a,&c,&b);
    if(c=='+')
		printf("%d+%d=%d\n",a,b,a+b);
    if(c=='-')
		printf("%d-%d=%d\n",a,b,a-b);
	if(c=='*')
		printf("%d*%d=%d\n",a,b,a*b);
    if(c=='/')
		printf("%d/%d=%d\n",a,b,a/b);    
    system("pause");
	return 0;
}
