#include <stdio.h>
#include <string.h>
#include <windows.h>
void OutPutWeek(int day)
{
	switch (day)
	{
	case 1:
		printf("星期一\n");
		break;
	case 2:
		printf("星期二\n");
		break;
	case 3:
		printf("星期三\n");
		break;
	case 4:
		printf("星期四\n");
		break;
	case 5:
		printf("星期五\n");
		break;
	case 6:
		printf("星期六\n");
		break;
	case 7:
		printf("星期日\n");
		break;
	default:
		printf("输入错误！\n");
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
		printf("请输入组号（1~12）：(若想退出请输入0)");
		scanf("%d", &group);
		if (group == 0)
			break;
		day = GetDay(group, &single);
		if(day>7||day<1)
        {
            printf("输入错误！请重新输入！\n");
            Sleep(1000);
            continue;
        }
		if (single == 1)
			printf("\n单周,");
		else if (single == 2)
			printf("\n双周,");
		OutPutWeek(day);
		printf("\n循环请等待1秒\n");
		Sleep(1000);
	}
	printf("\n谢谢使用，请按照安排仔细打扫卫生。\n");
	Sleep(1000);
	return 0;
}
