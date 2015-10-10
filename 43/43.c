#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b,c,n;
    a=0;
    b=1;
    n=2;
    while(n<=45)
{    
		c=a+b;
        a=b;
        b=c;
        n=n+1;
}
	printf("%d",c);
	system("pause");
	return 0;
}
