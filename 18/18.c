#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a;
    printf("加法选6,减法选7,乘法选8,除法选9.（输入完成后请按回车）\n");
    scanf("%d",&a);
     
    if (a==6)
    {
       printf("Jpj加法运算器\n");
        int d,e;
       printf("输入第一个数（输入完成后请按回车）\n");
        scanf("%d",&d);
       printf("输入第二个数（输入完成后请按回车）\n");
        scanf("%d",&e);
       printf("两个数的和是：%d+%d=%d\n",d,e,d+e);
    }
    else if (a==7){
       printf("Jpj减法计算器\n");
        int d,e;
       printf("输入第一个数（输入完成后请按回车）\n");
        scanf("%d",&d);
       printf("输入第二个数（输入完成后请按回车）\n");
        scanf("%d",&e);
       printf("两个数的差是：%d-%d=%d\n",d,e,d-e);
    }
    else if (a==8)
    {
        int d,e;
        printf("输入第一个数（输入完成后请按回车）\n");
        scanf("%d",&d);
        printf("输入第二个数（输入完成后请按回车）\n");
        scanf("%d",&e);
        printf("两个数的积是：%d*%d=%d\n",d,e,d*e);
    }
    else if (a==9)
    {
        double d,e;
        printf("输入第一个数（输入完成后请按回车）\n");
         scanf("%lf",&d);
         if(d==0)
         {
            printf("除法中除数不能为0\n");
            return 0;
         }
       printf("输入第二个数（输入完成后请按回车）\n");
        scanf("%lf",&e);
       printf("两个数的商是：%g/%g=%g\n",d,e,d/e);
    }
    else
    {
        printf("输入有误\n");
    }
	system("pause");
	return 0;
}
