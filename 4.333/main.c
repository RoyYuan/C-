//����������գ�����123456������ܼ�
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d=123456;
    printf("������������գ�123456�����");
    switch(d%7)
    {
        case 0:printf("���ա�"); break;
        case 1:printf("��һ��"); break;
        case 2:printf("�ܶ���"); break;
        case 3:printf("������"); break;
        case 4:printf("���ġ�"); break;
        case 5:printf("���塣"); break;
        case 6:printf("������"); break;
    }
    return 0;
}
