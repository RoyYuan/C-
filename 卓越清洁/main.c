#include <stdio.h>
#include <string.h>
#include <windows.h>
void OutPutWeek(int day)
{
	switch (day)
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

int GetDay(int group, int *single)
{
	if (group<1 || group>12)
		return 0;
	else if (group <= 6)
	{
		*single = 1;
		return group + 1;
	}
	else
	{
		*single = 2;
		return group % 7 + 2;
	}
}

int main()
{
	int group;
	int day, single = 0;

	while (1)
	{
		system("cls");
		printf("��������ţ�1~12����(�����˳�������0)");
		scanf("%d", &group);
		if (group == 0)
			break;
		day = GetDay(group, &single);
		if(day>7||day<1)
        {
            printf("����������������룡\n");
            Sleep(1000);
            continue;
        }
		if (single == 1)
			printf("\n����,");
		else if (single == 2)
			printf("\n˫��,");
		OutPutWeek(day);
		printf("\nѭ����ȴ�1��\n");
		Sleep(1000);
	}
	printf("\nллʹ�ã��밴�հ�����ϸ��ɨ������\n");
	Sleep(1000);
	return 0;
}
