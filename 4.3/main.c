#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=0,y;
    scanf("%d",&y);
    if(y<22)
        printf("�������\n");
    else
    {
        x=y<=30?0:y<=45?1:y<=55?2:3;
        switch(x){
        case 0:printf("��������ҵ��Ա"); break;
        case 1:printf("����������Ա");  break;
        case 2:printf("���βֿ����Ա"); break;
        case 3:printf("����");    break;
        }
        printf("��\n");
    }
    return 0;
}
