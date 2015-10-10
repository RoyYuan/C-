#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,i=0,j=0,m=0,n=0;
    char a[10][100000]={0},b[1];
    scanf("%d",&T);
    gets(b);
    for(i=0;i<T;i++)
    {
        gets(a[i]);
        while(a[i][j]=='A'||a[i][j]=='B')
            j++;
        for(m=0;m<j;m++)
            if(a[i][m]==a[i][m+1])
                n++;
        printf("%d\n",n);
        n=0;
        j=0;
    }
    return 0;
}
