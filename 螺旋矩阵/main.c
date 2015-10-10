#include <stdio.h>

int main(void)
{
    int n,i,j,r,sum=0;
    scanf("%d",&n);
    unsigned int s[n][n];
    r=n/2+1;
    for(i=0;i<r-1;i++)
    {
        for(j=0;j<2*(r-i)-1;j++)
            s[i][j+i]=4*(r-i-2)*(r-i-1)+4*(r-i)-3-j;
        for(j=i+1;j<2*(r-i)-1+i;j++)
            s[j][n-1-i]=4*(r-i-2)*(r-i-1)+1+2*(r-i-1)-j+i;
        for(j=i+1;j<2*(r-i)-1+i;j++)
            s[j][i]=4*(r-i-1)*(r-i-2)+1+4*(r-i-1)+j-i;
        for(j=0;j<2*(r-i)-1;j++)
            s[n-1-i][j+i]=4*(r-i-1)*(r-i)-n+j+2+2*i;
    }
    s[r-1][r-1]=1;
    for(i=0;i<n;i++)
    {
        sum+=s[i][i];
        sum+=s[n-1-i][i];
        for(j=0;j<n;j++)
            printf("%d\t",s[i][j]);
        printf("\n");
    }
    printf("%d",sum-1);
    return 0;
}
