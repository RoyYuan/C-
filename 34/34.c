#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,i;
    a=0;
    i=1;
    while (i<=100)
{	
		if (i%2==0)
        {
			a=a+i;
        }
        i=i+1;
}
	printf("%d",a);
    system("pause");
	return 0;
}
