#include <stdio.h>
#include <stdlib.h>
int main()
{
	int s,n,i,t;
    n=1;
    scanf("%d",&s);
    t=s%10;
	while(n>=1)
    {
		n=s/10;
		i=n%10;
        t=t+i;
        s=n;
    }
    printf("%d",t);
	system("pause");
	return 0;
}
