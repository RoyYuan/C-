//�²¿����̶����������жϴ�С
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int yangban=995,g;
    printf("��²�������(��λ��):\n");
    scanf("%d",&g);
    if(g==yangban)
    {
        printf("��ȷ��");
    }
    else
    {
        if(g<yangban)
        {
            printf("̫С��");
        }
        else
        {
            printf("̫��");
        }
    }
    return 0;
}
