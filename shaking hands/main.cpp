#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    int i,j,sum;
    int data[30][30];
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        memset(data,0,sizeof(int)*900);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                scanf("%d",&data[i][j]);
                sum+=data[i][j];
            }
        sum+=2*n;
        printf("%d\n",sum);
    }
    return 0;
}
