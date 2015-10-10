#include <stdio.h>

#define minof(a,b) ((a)<(b)?(a):(b))

int leave[31][25];
int v[31],n,bag;

int dp(int num,int x)
{
    if(num==1)
    {
        if(x>=v[1])
            leave[1][x]=x-v[1];
    }
    else
        leave[num][bag]=minof((dp(num-1,bag)),(dp(num-1,bag-v[num])-v[num]));
    return leave[num][bag];
}

int main()
{
    int i;
    int sum;
    scanf("%d%d",&bag,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
    }
    dp(n,bag);
    sum=bag;
    for(i=1;i<=n;i++)
    {
        if(sum>leave[i][bag])
            sum=leave[i][bag];
    }
    printf("%d",sum);
    return 0;
}
