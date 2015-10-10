#include <stdio.h>

int main(int argc, char *argv[])
{
	int n,i,j,t;
	scanf("%d",&n);
	i=n/10;
	t=1; 
	while(i!=0)
	{
		t++;
		j=i;
		i=j/10;	
	}
	printf("%d",t);
	return 0;
}
