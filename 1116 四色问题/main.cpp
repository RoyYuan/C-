#include <stdio.h>
#include <string.h>

int n;
int sum=0;
int contact[9][9];
int s[9];

void dfs(int num)
{
    int i,flag;
    bool color[5];
    memset(color,0,sizeof(color));
    if(num==n)
    {
        flag=0;
        for(i=1;i<=n;i++)
            if(contact[num][i])
            {
                color[s[i]]=1;
            }
        for(i=1;i<5;i++)
            if(!color[i])
            {
                flag++;
            }
        if(flag)
            sum+=flag;
        return;
    }
    if(num==1)
    {
        memset(s,0,sizeof(s));
        for(i=1;i<=4;i++)
        {
            s[1]=i;
            dfs(2);
        }
        return;
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            if(contact[num][i])
            {
                color[s[i]]=1;
            }
        }
        for(i=1;i<=4;i++)
        {
            if(!color[i])
            {
                s[num]=i;
                dfs(num+1);
                s[num]=0;
            }
        }
        return;
    }

    return;
}

int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&contact[i][j]);
        }
    }
    dfs(1);
    printf("%d\n",sum);
    return 0;
}
