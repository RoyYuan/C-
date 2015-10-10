#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,a,fa,b,fb,i,k;
    n=10000000;
    k=0;
    for(a=3;a<=n/2;a+=2)
    {
		fa=0;
        for(i=2;i<a;i++)
        {
			
			if(a%i==0)
            {
				fa=1;
                break;
            }
        }
        if(fa==0)
        {
			b=n-a;
			fb=0;
            for(i=2;i<b;i++)
            {
				if(b%i==0)
                {
					fb=1;
                    break;
                }
            }
            if(fb==0)
            {
				k++;
                printf("%d+%d=n  ",a,b);//ÔËËã½á¹û38807¡£¡£¡£
            }
        }
    }
    printf("%d",k);
	system("pause");
	return 0;
}
