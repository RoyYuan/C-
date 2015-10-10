#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,i,t,s;
    s=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
		scanf("%d",&t);
        s=s+t;
    }
    printf("%d",s);
	system("pause");
	return 0;
}
