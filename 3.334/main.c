//����ذ峤�Ϳ��ó��ذ�����͵�̺�۸�20.8Ԫÿƽ���ף�
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,s,money;
    printf("������ذ�ĳ��Ϳ���λΪ�ף���\n");
    scanf("%f %f",&a,&b);
    s=a*b;
    money=s*20.8;
    printf("�ذ����Ϊ:%fƽ����\n��̺�۸�Ϊ:%.2fԪ",s,money);
    return 0;
}
