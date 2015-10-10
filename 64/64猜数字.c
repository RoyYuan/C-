#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int a,b,sum;
    sum=6;
    srand((unsigned)time(NULL));
    a=rand()%100;
    printf("这是一个猜数字小游戏，共有6次机会，6次不中可是有惩罚的！\n                                  			Made by Roy.\n");
    while(1)
    {
		sum--;
        printf("请输入一个0到99之间的数字(按回车键确定）:");
        scanf("%d",&b);
        if(b>a)
			printf("大了，还剩下%d次机会，请继续\n",sum);
        if(b<a)
			printf("小了，还剩下%d次机会，请继续\n",sum);
        if(b==a)
        {
			printf("恭喜你，答对了！\n");
            break;
        }
        if(sum==0)
        {
			printf("没有机会了，系统将在10秒后关机！\n");
            system("shutdown -s -t 10");
            break;
        }
    }
    
	system("pause");
	return 0;
}
