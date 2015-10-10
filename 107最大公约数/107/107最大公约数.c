#include <stdio.h>
int main()
{
	int a,b,i;
	scanf("%d %d",&a,&b);
 	for(i=a;i>0;i--)
 	{
	 	while(a%i==0 && b%i==0)
	 	{
	 		printf("%d ",i);
            break;
	 	}
        if(a%i==0 && b%i==0)
        {
			break;
        }
 	}
    system("pause");
	return 0;
}
