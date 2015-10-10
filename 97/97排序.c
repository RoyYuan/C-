#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,j,a[100001]={0},n;
    scanf("%d",&n);
    int b[n];
    for(i=0;i<n;i++)
    {
		scanf("%d",&b[i]);
    }
    for(i=0;i<n;i++)
    {
		for(j=0;j<100001;j++)
        {
			while(b[i]==j)
            {
                a[j]++;
                break;
            }
        }
    }
    for(i=0;i<100001;i++)
    {
		while(a[i]>0)
        {
			printf("%d ",i);
            a[i]--;
        }
    }
	system("pause");
	return 0;
}
