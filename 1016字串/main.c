#include <stdio.h>
#include <stdlib.h>

int x[6];

void put(int k)
{
	int i;
	if(k==6)
	{
		for(i=1;i<6;i++)
			printf("%d",x[i]);
		printf("\n");
		return ;
	}
	for(i=0;i<2;i++)
	{
		x[k]=i;
		put(k+1);
	}
	return ;
}

int main()
{
	put(1);
	return 0;
}
