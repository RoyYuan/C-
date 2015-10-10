#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,t;
    a=0;
    t=0;
    while (t<=100)
{		
        a=a+t;
        t=t+1;
}
	printf("%d",a);
	system("pause");
	return 0;
}
