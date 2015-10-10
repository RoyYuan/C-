//failed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i,j,m;
    scanf("%d",&t);
    int n[t],c[t],nf[t],max[t];
    for(i=0;i<t;i++)
    {
        max[i]=1;
        scanf("%d",&n[i]);
        int a[n[i]];
        for(j=0;j<n[i];j++)
        {
            scanf("%d",&a[j]);
            if(max[i]<a[j])
                max[i]=a[j];
        }
        nf[i]=1;
        for(m=2;m<max[i];m++)
        {
            c[j]=0;
            for(j=0;j<n[i];j++)
            {
                if(a[j]%m!=0)
                {
                    c[j]++;
                }
                if(c[j]>=2)
                {
                    nf[i]=1;
                    break;
                }
            }
            if(nf[i]==0)
            {
                break;
            }
        }
    }
    for(i=0;i<t;i++)
    {
        if(nf[i]==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
