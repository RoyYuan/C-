#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    char s,y[10],x[100][60]={"0"};
    scanf("%d",&n);
    gets(y);
    memset(x,'x',6000);
    for(i=0;i<n;i++)
    {
        gets(x[i]);
        j=0;
        while(x[i][j]!=120&&j<61)
        {
            s=x[i][j-1];
            j++;
        }
        if(s%2==0)
            printf("even\n");
        else
            printf("odd\n");
    }
    return 0;
}
