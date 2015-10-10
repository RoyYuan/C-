#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long int sum=0;
int n;
int p[100],q[100];

int swap(int *a,int *b)
{
    if(*a==*b)
        return 0;
    *a+=*b;
    *b=*a-*b;
    *a-=*b;
    return 0;
}

void inverse()
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i]>p[j])
                sum++;
        }
    }
    sum%=1000000000+7;
}

void Perm(int list[100],int k,int m)
{
    int i;
    if(k==m-1)
    {
        inverse();
    }
    else
    {
        for(i=k;i<m;i++)
        {

            swap(&list[k],&list[i]);
            Perm(list,k+1,m);
            swap(&list[k],&list[i]);
        }
    }
}

void search()
{
    int i,j,y;
    for(i=n-2;i>=0;i--)
    {
        for(j=n-1;j>i;j--)
        {
            if(p[i]>p[j])
            {
                swap(&p[i],&p[j]);
                Perm(p,i+1,n);
                for(y=0;y<n;y++)
                    p[y]=q[y];
            }
        }
    }
}

int main()
{
    int i;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        memset(p,0,100*sizeof(int));
        for(i=0;i<n;i++)
        {
            scanf("%d",&p[i]);
            q[i]=p[i];
        }
        search();
        printf("%lu\n",sum);
    }
    return 0;
}
