//��Sֵ��n���û�����
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0,i,j=0,m;
    printf("������n��ֵ��nΪ����0����������\n");
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
    printf("������Ϊ��%d",n);
    system("pause");
    return 0;
}
