#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define M 1
#define F 0
#define shu ©§
#define heng ©¥
#define zs ©³
#define ys ©·
#define zx ©»
#define yx ©¿

typedef int Bool;

struct contects
{
    char firstname[5];
    char lastname[3];
    Bool sex;
    char tel[20];
    char qq[15];
    int group;
};

void menu(int max)
{
    system("cls");
    int i,j;
    printf("©³");
    for(i=1;i<=12;i++)
        printf("©¥");
    printf("©·\n");
    for(i=1;i<=max;i++)
    {
        printf(" ");
    }
    for(i=1;i<=22-max;i++)
    {
        printf("©§");
        for(j=1;j<=24;j++)
            printf(" ");
        printf("©§\n");
    }
    printf("©»");
    for(i=1;i<=12;i++)
        printf("©¥");
    printf("©¿\n");
}


int main()
{
    int max;
    menu(max);
    return 0;
}
