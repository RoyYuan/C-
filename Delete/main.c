#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,sum=0,n,k;
    int x[100],s[101];
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        memset(x,0,100*sizeof(int));
        memset(s,0,101*sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
            s[x[i]]++;
        }
        scanf("%d",&k);
        for(i=1;i<=n;i++)
        {
            while(s[i]>1)
            {
                if(k)
                {
                    s[i]--;
                    k--;
                }
                else
                    break;
            }
            if(k)
                continue;
            else
                break;
        }
        if(k)
        {
            for(i=k;i>0;i--)
                sum--;
        }

        for(i=1;i<=n;i++)
        {
            if(s[i])
                sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
