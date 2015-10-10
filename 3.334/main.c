//输入地板长和宽，得出地板面积和地毯价格（20.8元每平方米）
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a,b,s,money;
    printf("请输入地板的长和宽（单位为米）：\n");
    scanf("%f %f",&a,&b);
    s=a*b;
    money=s*20.8;
    printf("地板面积为:%f平方米\n地毯价格为:%.2f元",s,money);
    return 0;
}
