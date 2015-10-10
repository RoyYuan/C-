#include <stdio.h>

int s[11][2],high=1,wide=1;
int height=1,width=1;
int level[11],father[11];
int n;

int tall(int x)
{
    if(s[x][0] || s[x][1])
    {
        high++;
        if(s[x][0])
        {
            tall(s[x][0]);
        }
        if(s[x][1])
        {
            tall(s[x][1]);
        }
        high--;
    }
    else
    {
        if(height<high)
            height=high;
        return 0;
    }
    return 0;
}

int levelc(int x)
{
    if(s[x][0] || s[x][1])
    {
        level[s[x][0]]=level[x]+1;
        level[s[x][1]]=level[x]+1;
    }
    return 0;
}

int wid()
{
    int i,j;
    level[1]=1;
    for(i=1;i<=n;i++)
        levelc(i);
    for(i=1;i<=height;i++)
    {
        wide=0;
        for(j=1;j<=n;j++)
            if(level[j]==i)
                wide++;
        if(width<wide)
            width=wide;
    }
    return width;
}

int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&s[i][0],&s[i][1]);
        father[s[i][0]]=i;
        father[s[i][1]]=i;
    }
    tall(1);
    wid();
    if(n==1)
        width=1;
    printf("%d %d\n",width,height);
    return 0;
}
