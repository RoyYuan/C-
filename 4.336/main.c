//������⳵��
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float s,money;
    printf("��������⳵��ʻ���������\n");
    scanf("%f",&s);
    if(s<3)
    {
        money=7;
    }
    else
    {
        if(s<8)
        {
            money=7+1.7*(int)(s-2);
        }
        else
        {
            money=15.5+2*(int)(s-7);
        }
    }
    printf("Ӧ�����Ϊ��%.2fԪ",money);
    return 0;
}
