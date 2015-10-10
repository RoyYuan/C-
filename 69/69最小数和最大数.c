#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,t,max,min;
    scanf("%d",&n);
    scanf("%d",&t);
    max=t;
    min=t;
    for(i=2;i<=n;i++)
    {
        scanf("%d",&t);
        if(t>max)
		{
            max=t;
        }
        if(t<min)
		{
        	min=t;
        }
    }
    printf("%d %d",min,max);
    
	system("pause");
	return 0;
}
