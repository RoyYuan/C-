#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a=987654321,b=1,c=2,d=0;
    for(b=1;b<=a;b++)
    {
		if(a%b==0)
        {
			for(c=2;c<=b-1;c++)
            {
				if(b%c==0)
                {	
                    d=1;
                    break;
                }
            }
            if(d==0)
            {
				printf("%d\n",b);
            }
            d=0;
        }
    }
	system("pause");
	return 0;
}
