#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,m=0,i,j;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
		scanf("%d",&a[i]);
    }
    int b[1001]={0};
    for(j=0;j<n;j++)
    {
		for(i=0;i<1001;i++)
        {	
			if(i==a[j])
			{
                b[i]++;
            }
        }
    }
    for(i=0;i<1001;i++)
    {
		while(b[i]>1)
        {
			b[i]--;
        }
		m=m+b[i];       
    }
    printf("%d\n",m);
    for(i=0;i<1001;i++)
    {
		if(b[i]==1)
        {
			printf("%d ",i);
            b[i]--;
        }
    }
	system("pause");
	return 0;
}
