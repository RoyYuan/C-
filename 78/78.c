#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[4][3],i,j;
    for(i=0;i<4;i++)
    {
		for(j=0;j<3;j++)
        {
			scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<4;i++)
    {
		for(j=0;j<3;j++)
        {
			printf("%d ",a[i][j]);
        }
        printf("\n");
    }
	system("pause");
	return 0;
}
