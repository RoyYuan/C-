#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a;
    printf("�ӷ�ѡ6,����ѡ7,�˷�ѡ8,����ѡ9.��������ɺ��밴�س���\n");
    scanf("%d",&a);
     
    if (a==6)
    {
       printf("Jpj�ӷ�������\n");
        int d,e;
       printf("�����һ������������ɺ��밴�س���\n");
        scanf("%d",&d);
       printf("����ڶ�������������ɺ��밴�س���\n");
        scanf("%d",&e);
       printf("�������ĺ��ǣ�%d+%d=%d\n",d,e,d+e);
    }
    else if (a==7){
       printf("Jpj����������\n");
        int d,e;
       printf("�����һ������������ɺ��밴�س���\n");
        scanf("%d",&d);
       printf("����ڶ�������������ɺ��밴�س���\n");
        scanf("%d",&e);
       printf("�������Ĳ��ǣ�%d-%d=%d\n",d,e,d-e);
    }
    else if (a==8)
    {
        int d,e;
        printf("�����һ������������ɺ��밴�س���\n");
        scanf("%d",&d);
        printf("����ڶ�������������ɺ��밴�س���\n");
        scanf("%d",&e);
        printf("�������Ļ��ǣ�%d*%d=%d\n",d,e,d*e);
    }
    else if (a==9)
    {
        double d,e;
        printf("�����һ������������ɺ��밴�س���\n");
         scanf("%lf",&d);
         if(d==0)
         {
            printf("�����г�������Ϊ0\n");
            return 0;
         }
       printf("����ڶ�������������ɺ��밴�س���\n");
        scanf("%lf",&e);
       printf("�����������ǣ�%g/%g=%g\n",d,e,d/e);
    }
    else
    {
        printf("��������\n");
    }
	system("pause");
	return 0;
}
