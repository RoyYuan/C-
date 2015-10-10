#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n,t,i,j;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
		scanf("%d",&a[i]);
    }
	for(i=0;i<n;i++)
    {
		for(j=i+1;j<n;j++)
        {
			if(a[i]<a[j])
            {
				t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
        }
    }
    for(i=0;i<n;i++)
    {
		printf("%d ",a[i]);
    }
	system("pause");
	return 0;
}
