//求S值，n由用户输入
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0,i,j=0,m;
    printf("请输入n的值（n为大于0的整数）：\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        m=0;
        for(j=1;j<=n;j++)
        {
            m+=j;
            printf("%d",j);
        }
        n+=m;
    }
    printf("计算结果为：%d",n);
    system("pause");
    return 0;
}
