#include <stdio.h>
#include <stdlib.h>

int f(int n,int s)
{
    if(n==1)
        return s;
    else
    {
        if(n%2!=0)
        {
            n=3*n+1;
            s++;
            s=f(n,s);
            return s;
        }
        else
        {
            n=n/2;
            s++;
            s=f(n,s);
            return s;
        }
    }
}



int main()
{
    int t,i,j;
    scanf("%d",&t);
    int n[100]={0},s[100]={0};
    for(i=0;i<t;i++)
    {
        scanf("%d",&n[i]);
        s[i]=f(n[i],s[i]);
        printf("%d\n",s[i]);
    }
    return 0;
}
