#include <stdio.h>
#include <string.h>
void OutPutWeek(int day)
{
	switch(day)
	{
	case 1:
		printf("����һ\n");
		break;
	case 2:
		printf("���ڶ�\n");
		break;
	case 3:
		printf("������\n");
		break;
	case 4:
		printf("������\n");
		break;
	case 5:
		printf("������\n");
		break;
	case 6:
		printf("������\n");
		break;
	case 7:
		printf("������\n");
		break;
	default:
		printf("�������\n");
		break;
	}
}

int GetDay(int group,int *single)
{
	if(group<1 || group>12)
		return 0;
	else if(group<=6)
	{
		*single = 1;
		return group+1;
	}
	else
	{
		*single = 2;
		return group%7+2;
	}
}

void main()
{
	int group;
	int day,single=0;
	char x;
	while(1)
    {
        printf("��������ţ�1~12����(�����˳�������Q)");
        scanf("%c",&x);
        if(x=='Q')
            break;
        group=x-48;
        day=GetDay(group,&single);
        if(single==1)
            printf("\n���ܣ�");
        else if(single==2)
            printf("\n˫�ܣ�");
        OutPutWeek(day);
    }
    printf("ллʹ�ã��밴�հ�����ϸ��ɨ������");
    getchar();
}
