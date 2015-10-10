#include <stdio.h>
#include <string.h>

int n,m,k;
int w[100][100];
int maxeat;
int f=1;

void dp(int x,int y,int leave)//x.y格
{
    if(leave==0)
        f==0;
    if(f==0)
        return;
    if(k-leave>maxeat)
            maxeat=k-leave;
    //若可以吃下当前格子蛋糕
    if(leave>=w[x][y])
    {
        leave-=w[x][y];
        //向右走
        if(x+1<n)
            dp(x+1,y,leave);
        //向下走
        if(y+1<m)
            dp(x,y+1,leave);
        if(k-leave>maxeat)
            maxeat=k-leave;
        leave+=w[x][y];
    }
    if(x+1<n)
        dp(x+1,y,leave);
    if(y+1<m)
        dp(x,y+1,leave);
    if(k-leave>maxeat)
        maxeat=k-leave;
    return;
}

int main()
{
    int i,j;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        f=1;
        maxeat=0;
        memset(w,0,sizeof(int)*10000);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&w[i][j]);
        dp(0,0,k);
        printf("%d\n",maxeat);
    }
    return 0;
}
