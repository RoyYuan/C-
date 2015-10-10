#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b,c;
    for(a=0;a<=36;a++)
    {
		for(b=0;b<=18;b++)
        {
			for(c=0;c<=12;c++)
			{
				if (a+2*b+3*c==36)
                {
					printf("%d %d %d\n",a,b,c);
                }
            }
        }
    }
	system("pause");
	return 0;
}
