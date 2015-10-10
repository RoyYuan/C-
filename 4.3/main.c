#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=0,y;
    scanf("%d",&y);
    if(y<22)
        printf("输入错误。\n");
    else
    {
        x=y<=30?0:y<=45?1:y<=55?2:3;
        switch(x){
        case 0:printf("担任外勤业务员"); break;
        case 1:printf("担任内勤文员");  break;
        case 2:printf("担任仓库管理员"); break;
        case 3:printf("退休");    break;
        }
        printf("。\n");
    }
    return 0;
}
