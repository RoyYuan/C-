//求S值，n由用户输入
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,m,s=0;
    printf("请输入n的值（n为大于0的整数）：\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        m=0;
        for(j=1;j<=i;j++)
        {
            m+=j;
        }
        s+=m;
    }
    printf("计算结果为：%d",s);
    return 0;
}
