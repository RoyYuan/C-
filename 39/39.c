#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
	int a,b,c;
    a=1;
    scanf("%d",&b);
    while(a<=b)
{    
		system("cls");
        c=1;
        while(c<a)
{        
         printf(" ");
         c=c+1;
}         
		printf("H");
        Sleep(1000);
        a=a+1;
}        
	system("pause");
	return 0;
}
