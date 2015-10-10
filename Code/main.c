#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[10000];
int n;

int gcd(int a,int b)
{
	return (b==0?a:gcd(b,a%b)) ;
}

int g(int x)
{
    return x*(x-1);
}

int calc()
{
	int res=0,i,j,s;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
            s=gcd(a[i],a[j]);
            res+=g(s);
            res%=10007;
            res+=g(s);
            res%=10007;
		}
    for(i=0;i<n;i++)
    {
        res+=g(a[i]);
        res%=10007;
    }
	return res;
}


int main()
{
    int i,sum=0;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a,0,10000*sizeof(int));
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sum=calc();
        printf("%d\n",sum);
    }
    return 0;
}
