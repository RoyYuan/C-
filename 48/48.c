#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b,n,s;
    a=2;
    b=2;
    n=0;
    s=0;
    for(b=2;b<=12345;b++)
    {
		for(a=2;a<=b-1;a++)
        {
			if (b%a==0)
            n=1;
        }
    s=s+n;
    n=0;    
    }
    s=12344-s;
    printf("%d",s);        
	system("pause");
	return 0;
}
