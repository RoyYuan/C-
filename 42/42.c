#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,s;
    a=1;
    s=0;
    while(a<=123456)
{    
		if (a%7==0 || a%10==7)
{        
        s=s+a;
}
        a=a+1;
}
	printf("%d",s);
	system("pause");
	return 0;
}
