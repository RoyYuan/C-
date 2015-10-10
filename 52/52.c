#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,a,b,fa,fb,i;
    for(n=4;n<=100;n+=2)
    {
		for(a=2;a<=n/2;a++)
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
						printf("%d=%d+%d\n",n,a,b);
                    }
                    
                
            }
        }
    }
	system("pause");
	return 0;
}
