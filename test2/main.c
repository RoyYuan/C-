#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,i;
    for(i=1;i<=3;i++)
    {
        scanf("%d",&m);
        if(m==123456)
        {
            printf("��ȷ��\n");
            break;
        }
        else
        {
            if(i==3)
            {
                printf("�����˳���\n");
                break;
            }
            printf("�����������롣\n");
        }
    }
    return 0;
}
