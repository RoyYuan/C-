#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
	int a,b,c;
	c=1;
    scanf("%d",&a);
    while (c<=a)
{    
		system("cls");
		
        b=1;
        while (b<=c)
{        
			printf(" ");
            b=b+1;
}            
		printf(" O\n");
		
        b=1;
        while (b<=c)
{        
			printf(" ");
            b=b+1;
}       
		printf("<H>\n");
		
        b=1;
        while (b<=c)
{        
			printf(" ");
            b=b+1;
}       
		printf("I I\n");
        c=c+1;
        Sleep(1000);
}               
	system("pause");
	return 0;
}
