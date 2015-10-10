#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main(void)
{
 int a[999]={0},i=0,j=0,sum=0,p;
 char b[999]={"0"};
 printf("请选择加减法或乘除法，加减法输入1，乘除法输入2,以等于号结束。\n");
 if(scanf("%d",&p)==1&&(p==1||p==2))
 {

  while(scanf("%d%c",&a[i],&b[j])==2&&b[j]!='=')
  {
   j++;
   i++;
   continue;
  }
  sum=a[0];
  for(j=0;j<=i;j++)
  {
   switch(b[j]){
   case '+':sum+=a[j+1]; break;
   case '-':sum-=a[j+1]; break;
   case '*':sum*=a[j+1]; break;
   case '/':sum=(double)(sum)/(double)(a[j+1]); break;
   }
  }
  printf("原式值为：");
  if(p==1)
   printf("%d\n",sum);
  if(p==2)
   printf("%d\n",sum);
  printf("Test Time!\nThere are 10 questions.Take it easy and do your best!\n");
  if(p==1)
  {
   for(j=1;j<=10;j++)
   {
    srand(time(NULL));
    a[0]=rand()%10;
    sum=a[0];
    printf("%d",a[0]);
    for(i=0;i<10;i++)
    {
     srand(time(NULL));
     a[i+1]=rand()%10;
     b[i]=rand()%2==0?'+':'-';
     switch(b[i]){
      case '+':sum+=a[i+1]; break;
      case '-':sum-=a[i]; break;
     }
     printf("%c%d",b[i],a[i+1]);
    }
    printf("=?\n");
   }
  }
  else
  {
   for(j=1;j<=10;j++)
   {
    srand(time(NULL));
    a[0]=rand()%10;
    sum=a[0];
    printf("%d",a[0]);
    for(i=0;i<10;i++)
    {
     srand(time(NULL));
     a[i+1]=rand()%10;
     b[i]=rand()%2==0?'*':'/';
     switch(b[i]){
      case '+':sum*=a[i+1]; break;
      case '-':sum/=a[i]; break;
     }
     printf("%c%d",b[i],a[i+1]);
    }
    printf("=?\n");
   }
  }
 }
 else
  printf("Wrong Input!\n");
 return 0;
}
