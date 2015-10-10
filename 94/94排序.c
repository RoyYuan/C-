#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[11]={0},grade,i;
    for(i=0;i<=4;i++)
    {
		scanf("%d",&grade);
        a[grade]++;
    }
    for(i=10;i>=0;i--)
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
