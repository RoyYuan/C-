//�Ӽ�������������ֵ�����������ֵ
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[3],t=0,i;
    printf("��������������\n");
    for(i=0;i<3;i++)
    {
        scanf("%d",&x[i]);
        if(x[i]>t)
        {
            t=x[i];
        }
    }
    printf("�����������ǣ�%d",t);
    return 0;
}
