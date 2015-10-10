#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,k,i,n=0;
    for(m=2;m<=100000000;m++)
    {
                       k=m-1;
    for(i=2;i<=k;i++)
    {
    if(m%i==0)
    break;
    }
    if(i<=k)
    continue;
    n++;
    printf("%9d",m);
    if(n%9==0)
    printf("\n");
    }
  
  system("PAUSE");	
  return 0;
}
