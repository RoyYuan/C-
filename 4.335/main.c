//�ж������ַ�����ĸ�ַ��������ַ�
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    printf("������һ���ַ���\n");
    scanf("%c",&ch);
    if(ch>=48 && ch<=57)
    {
        printf("����ַ��������ַ���\n");
    }
    else
    {
        if((ch>=65 && ch<=90)||(ch>=97 && ch<=122))
        {
            printf("����ַ�����ĸ�ַ���\n");
        }
        else
        {
            printf("����ַ��������ַ���\n");
        }
    }
    return 0;
}
