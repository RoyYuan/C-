#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,m;
    printf("«Î ‰»Înµƒ÷µ£∫\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<i;j++)
        {
            printf(" ");
        }
        for(m=n;m>=i;m--)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
