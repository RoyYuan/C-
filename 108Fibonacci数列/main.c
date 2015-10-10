#include <stdio.h>

int main(int argc, char *argv[])
{
	int n,i,a[40];
	scanf("%d",&n);
	a[0]=1;
	a[1]=1;
	for(i=2;i<40;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	printf("%d",a[n-1]);
	return 0;
}
