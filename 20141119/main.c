#include <stdio.h>
#include <stdlib.h>
int pict[100][100];
int m,n,sum=0;
void dfs(int r,int c)
{
    int d;
    if(r<0||r>=m||c<0||c>=n)
        return;
    if(pict[r][c]!=1)
        return;
    pict[r][c]=0;
    for(d=-1;d<2;d++)
        if(d)
        {
            dfs(r+d,c);
            dfs(r,c+d);
        }
}
int main()
{
    int i,j;
    if(scanf("%d%d",&m,&n)==2&&m&&n)
    {
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                scanf("%d",&pict[i][j]);
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                if(pict[i][j]==1)
                {
                    sum++;
                    dfs(i,j);
                }
        printf("%d\n",sum);
    }
    return 0;
}
