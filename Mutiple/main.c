#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int a[10000];
    int n,i,j,sum;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        memset(a,0,10000*sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[j]%a[i]==0 && a[j]!=a[i])
                {
                    sum+=j+1;
                    break;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
