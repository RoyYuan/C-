#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b,k;
    printf("��������������ֵ��");
    scanf("%d %d",&a,&b);
    k=a;
    a=b;
    b=k;
    printf("������ֵ������ֱ�Ϊ��%d %d\n",a,b);
	system("pause");
	return 0;
}
