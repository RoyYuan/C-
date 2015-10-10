#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i,j,n,s,o;
    char a[10][10000]={0};
    scanf("%d",&t);
    gets(a);
    for(i=0;i<t;i++)
    {
        n=0;
        o=0;
        s=0;
        gets(a[i]);
        while(a[i][n]>=97 && a[i][n]<=122)
            n++;
        for(j=(n+1)/2;j>0;j--)
        {
            while(a[i][o]!=a[i][n-o-1])
            {
                if(a[i][o]>=a[i][n-o-1])
                    a[i][o]--;
                else
                    a[i][n-o-1]--;
                s++;
            }
            o++;
        }
        printf("%d\n",s);
    }
    return 0;
}
