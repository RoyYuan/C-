#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
	int a[999]={0},c[999]={0},i=0,j=0,sum=0,p,ans,score=0,mis=0,e[10];
	char b[999]={"0"};
	double sum1,d[999]={0},ans1;
	printf("请选择加减法或乘除法，加减法输入1，乘除法输入2,以等于号结束。\n");
	if(scanf("%d",&p)==1&&(p==1||p==2))
	{
		while(scanf("%d%c",&a[i],&b[j])==2&&b[j]!='=')
		{
		   j++;
		   i++;
		   continue;
		}
		if(p==1)
			sum=a[0];
		else
			sum1=a[0];
		for(j=0;j<=i;j++)
		{
		   switch(b[j]){
		   case '+':sum+=a[j+1]; break;
		   case '-':sum-=a[j+1]; break;
		   case '*':sum1*=a[j+1]; break;
		   case '/':sum1=sum1/(double)(a[j+1]); break;
		   }
		}
		printf("原式值为：");
		if(p==1)
		   printf("%d\n",sum);
		if(p==2)
		   printf("%.2f\n",sum1);
		Sleep(1000);
		printf("Test Time!\nThere are 10 questions.Take it easy and do your best!\n");
		printf("P.S:乘除法结果请保留两位小数。\n");
		Sleep(3000);
		if(p==1)
		{
			srand((unsigned)time(NULL));
			for(j=1;j<=10;j++)
			{
				a[0]=rand()%10;
				sum=a[0];
				printf("%d",a[0]);
				for(i=0;i<10;i++)
				{
					a[i+1]=rand()%10;
					b[i]=rand()%2==0?'+':'-';
					switch(b[i]){
					case '+':sum+=a[i+1]; break;
					case '-':sum-=a[i+1]; break;
					}
					printf("%c%d",b[i],a[i+1]);
				}
				printf("=?\n");
				c[j]=sum;
				if(scanf("%d",&ans)==1 && ans==sum)
					score++;
				else
				{
					e[mis]=j;
					mis++;
				}
			}
			printf("10道题总计答对%d道，得分%d分。\n",score,score*10);
			if(mis)
			{
				printf("第");
				for(i=1;i<=mis;i++)
				{
					printf(" %d ",e[i-1]);
				}
				printf("道错误。\n");
			}
			printf("十道题的答案分别为：\n");
			for(i=1;i<=10;i++)
				printf("(%d)%d\t",i,c[i]);
			printf("\n");
		}
		else
		{
			srand(time(NULL));
			for(j=1;j<=10;j++)
			{
				a[0]=rand()%10+1;
				sum1=a[0];
				printf("%d",a[0]);
				for(i=0;i<10;i++)
				{
					a[i+1]=rand()%10+1;
					b[i]=rand()%2==0?'*':'/';
					switch(b[i]){
					case '*':sum1*=a[i+1]; break;
					case '/':sum1/=(double)(a[i+1]); break;
					}
					printf("%c%d",b[i],a[i+1]);
				}
				printf("=?\n");
				d[j]=sum1;
				if(scanf("%lf",&ans1)==1 && ans1-sum1<0.05 &&ans1-sum1>-0.05)
					score++;
				else
				{
					e[mis]=j;
					mis++;
				}
			}
			printf("10道题总计答对%d道，得分%d分。\n",score,score*10);
			if(mis)
			{
				printf("第");
				for(i=1;i<=mis;i++)
					printf("%d",e[i-1]);
				printf("道错误。\n");
			}
			printf("十道题的答案分别为：\n");
			for(i=1;i<=10;i++)
				printf("(%d)%.2f\t",i,d[i]);
			printf("\n");
		}
	}
	else
        printf("Wrong Input!\n");
	return 0;
}
