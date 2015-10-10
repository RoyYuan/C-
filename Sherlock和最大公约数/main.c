#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i,j;
    scanf("%d",&t);
    int n[t],max[t]={0},min[t]={0};
    for(i=0;i<t;i++)
    {
        scanf("%d",&n[i]);
        int a[i][n[i]];
        for(j=0;j<n[i];j++)
        {
            scanf("%d",&a[i][j]);
            max[i]=max[i]>=a[i][j]?max[i]:a[i][j];
            min[i]=min[i]<=a[i][j]?min[i]:a[i][j];
        }

    }
    return 0;
}
