#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b,c,d;
    for(a=1;a<=9;a=a+1)
{
		for(b=0;b<=9;b=b+1)
        {
			for(c=0;c<=9;c=c+1)
            {
			d=a*a*a+b*b*b+c*c*c;
            if(d==a*100+b*10+c)
            {
				
				printf("%d\n",d);
            }
            }
        }
}
	system("pause");
	return 0;
}
