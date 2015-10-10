#include <stdio.h>

int main(int argc, char *argv[])
{
	int n,i;
	scanf("%d",&n);
	int a[n],b[n],c[n],t[n];
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
		t[i]=a[i]*b[i]/c[i];
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",t[i]);
	}
	return 0;
}
