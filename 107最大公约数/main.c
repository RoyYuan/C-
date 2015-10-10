#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int a,b,i;
	scanf("%d %d",&a,&b);
 	for(i=a;i>=1;i--)
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
	return 0;
}
