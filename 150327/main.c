#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned int i,j,k,l,f,x[5];
    unsigned long int n,m;
    for(i=10;i*i<99999;i++)
    {
        n=i*i;
        m=n;
        j=0;
        while(m!=0)
        {
            x[j++]=m%10;
            m/=10;
        }
        f=0;
        for(k=0;k<j-1;k++)
        {
            for(l=k+1;l<j;l++)
                if(x[k]==x[l])
                {
                f=1;
                break;
                }
            if(f==1)
            {
                printf("%lu\t",n);
                break;
            }
        }
    }
    return 0;
}
