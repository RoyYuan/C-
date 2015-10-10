#include <stdio.h>

int main(int argc, char *argv[])
{
	int n,i,fn=0;
	char a='t',b='n';
	scanf("%d",&n);
	for(i=2;i<n;i++)
		if(n%i==0)
		{
			fn=1;
			printf("\\%c",b);
			break;
		}
	if(fn==0)
		printf("\\%c",a);	
	return 0;
}
