#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned long int n;
    int i=0,x[100]={0},f=0,j;
    scanf("%lu",&n);
    n*=2;
    while(n!=0)
    {
        x[i++]=n%10;
        n/=10;
    }
    if(i%2==0)
        for(j=0;j<i/2;j++)
        {
            if(x[i/2-1-j]==x[i/2+j])
                continue;
            else
            {
                f=1;
                break;
            }
        }
    else
        for(j=1;j<i/2;j++)
        {
            if(x[i/2-j]==x[i/2+j])
                continue;
            else
            {
                f=1;
                break;
            }
        }
    if(f==0)
        puts("YES.");
    else
        puts("NO.");
    return 0;
}

