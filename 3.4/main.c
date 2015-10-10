#include <stdio.h>
#include <stdlib.h>

int main()
{
    float f,c;
    printf("请输入华氏度数：");
    scanf("%f",&f);
    c=5.0/9.0*(f-32);
    printf("其对应的摄氏度数为：%.2f",c);
    return 0;
}
