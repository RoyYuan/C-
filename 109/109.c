#include <stdio.h>
#include <string.h>
void OutPutWeek(int day)
{
	switch(day)
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
        printf("请输入组号（1~12）：(若想退出请输入Q)");
        scanf("%c",&x);
        if(x=='Q')
            break;
        group=x-48;
        day=GetDay(group,&single);
        if(single==1)
            printf("\n单周，");
        else if(single==2)
            printf("\n双周，");
        OutPutWeek(day);
    }
    printf("谢谢使用，请按照安排仔细打扫卫生。");
    getchar();
}
