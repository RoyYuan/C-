#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b,c,n;
    a=2;
    b=2;
    c=0;
    n=0;
    for(a=2;a<=100;a++)
    {
		for(b=2;b<=a-1;b++)
        {
			if(a%b==0)
            {
				c=1;
            }
        }
        if(c!=1)
        {			
            n=n+a;
		}
        c=0;
    }
    printf("%d",n);
            
	system("pause");
	return 0;
}
