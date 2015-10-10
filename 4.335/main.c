//判断数字字符、字母字符和其他字符
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    printf("请输入一个字符：\n");
    scanf("%c",&ch);
    if(ch>=48 && ch<=57)
    {
        printf("这个字符是数字字符。\n");
    }
    else
    {
        if((ch>=65 && ch<=90)||(ch>=97 && ch<=122))
        {
            printf("这个字符是字母字符。\n");
        }
        else
        {
            printf("这个字符是其他字符。\n");
        }
    }
    return 0;
}
