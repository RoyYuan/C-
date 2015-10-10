#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b,t,fa,fb,i=0;
    for(a=100;a<=198;a++)
    {
		fa=0;
		for(t=2;t<a;t++)
        {
			if(a%t==0)
            {
				fa=1;
                break;
            }
        }
        if(fa==0)
        {
			b=a+2;
			fb=0;
            for(t=2;t<b;t++)
            {
				if(b%t==0)
                {
					fb=1;
                    break;
                }
            }
            if(fb==0)
            {
				printf("%d %d\n",a,b);
                i++;
            }
        }
    }
    printf("i=%d",i);
	system("pause");
	return 0;
}
