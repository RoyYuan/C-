#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int a,b,sum;
    sum=6;
    srand((unsigned)time(NULL));
    a=rand()%100;
    printf("����һ��������С��Ϸ������6�λ��ᣬ6�β��п����гͷ��ģ�\n                                  			Made by Roy.\n");
    while(1)
    {
		sum--;
        printf("������һ��0��99֮�������(���س���ȷ����:");
        scanf("%d",&b);
        if(b>a)
			printf("���ˣ���ʣ��%d�λ��ᣬ�����\n",sum);
        if(b<a)
			printf("С�ˣ���ʣ��%d�λ��ᣬ�����\n",sum);
        if(b==a)
        {
			printf("��ϲ�㣬����ˣ�\n");
            break;
        }
        if(sum==0)
        {
			printf("û�л����ˣ�ϵͳ����10���ػ���\n");
            system("shutdown -s -t 10");
            break;
        }
    }
    
	system("pause");
	return 0;
}
