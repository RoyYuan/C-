#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b,c;
    a=1;
    c=1;
    while(a<=5)
{		
		b=1;
        while(b<=a)
{        
			printf("%d ",c);
            b=b+1;
            c=c+1;
}       
		printf("\n");
		a=a+1;
}        
	system("pause");
	return 0;
}
