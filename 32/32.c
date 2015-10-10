#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,t;
    a=0;
    t=1;
    while (t<=100)
{		
		if (t%7==0 || t%10==7)
        a=a+t;
    t=t+1;
}
	printf("%d\n",a);
	system("pause");
	return 0;
}
