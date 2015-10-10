#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void*a,const void*b)
{
    return *(int*)b-*(int*)a;
}
int gys(int a,int b)
{
	int r=a%b;
	while(r)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}
int main()
{
    int t,i,p,q;
    long int n,m[100000],max=0,j,k,ans[100000],s;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        max=0;
        p=0;
        q=99999;
        scanf("%ld",&n);
        memset(ans,1,10000*sizeof(long int));
        memset(m,1,100000*sizeof(long int));
        for(j=0;j<n;j++)
            scanf("%ld",&m[j]);
        qsort(m,100000,sizeof(int),comp);
        for(j=p;j<q;j++)
        {
            s=0;
            for(k=p+1;k<=q;k++)
            {
                if(ans[s]>m[k])
                {
                    q=k;
                    break;
                }
                ans[s++]=gys(m[j],m[k]);
                if(max<ans[s])
                    max=ans[s];
            }

        }
        printf("Case #%d: %ld\n",i+1,max);
    }
    return 0;
}
