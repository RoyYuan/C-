//��Sֵ��n���û�����
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,m,s=0;
    printf("������n��ֵ��nΪ����0����������\n");
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
    printf("������Ϊ��%d",s);
    return 0;
}
