#include <stdio.h>
#include <string.h>
const int maxn=100+5;
char pic[maxn][maxn];
int m,n,idx[maxn][maxn];

void dfs(int r,int c,int id)
{
    if(r<0||r>=m||c<0||c>=n)    return;
    if(idx[r][c]>0||pic[r][c]!='1') return;
    idx[r][c]=id;
    for(int dr=-1;dr<2;dr++)
        for(int dc=-1;dc<2;dc++)
            if(dr||dc)  dfs(r+dr,c+dc,id);
}

int main()
{
    while(scanf("%d%d",&m,&n)==2&&m&&n)
    {
        for(int i=0;i<m;i++)
            scanf("%s",pic[i]);
        memset(idx,0,sizeof(int)*maxn);
        int cnt=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(idx[i][j]==0&&pic[i][j]=='1')    dfs(i,j,++cnt);
        printf("%d\n",cnt);
    }
    return 0;
}
