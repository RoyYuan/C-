#include <stdio.h>

int main(int argc, char *argv[])
{
	int n,i,m;
	scanf("%d",&n);
	i=1;
	while(n>0)
	{
		n=n-i;
		i++;	
	}
	m=0-n;
	if(i%2==0)
	{

		printf("%d/%d",m+1,i-m-1);	
	}
	else
	{
		printf("%d/%d",i-m-1,m+1);
	}
	return 0;
}
