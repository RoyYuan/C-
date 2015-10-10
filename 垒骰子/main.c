#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m[7][7];
long long int n;
unsigned long int sum=0,sum1=1;
int x[10000];

void f()
{
    int i;
    if(n==0)
        return ;
    for(i=1;i<7;i++)
    {
        if(!m[x[n+1]][i])
        {
            switch(i)
            {
                case 1:x[n--]=4;    break;
                case 2:x[n--]=5;    break;
                case 3:x[n--]=6;    break;
                case 4:x[n--]=1;    break;
                case 5:x[n--]=2;    break;
                case 6:x[n--]=3;    break;
            }
            sum1*=4;
            sum1%=1000000007;
            f();
        }
        else
            continue;
    }
}


int main()
{
    int k,i,p,q;
    memset(m,0,49*sizeof(int));
    scanf("%lld %d",&n,&k);
    for(i=1;i<=k;i++)
    {
        scanf("%d %d",&p,&q);
        m[p][q]=1;
        m[q][p]=1;
    }
    for(i=1;i<7;i++)
    {
        x[n]=i;
        sum1=4;
        n--;
        f();
        sum+=sum1;
        sum%=1000000007;
    }
    printf("%lu",sum);
    return 0;
}
