#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
	int a,b,c;
    scanf("%d",&c);
	a=1;
    while (a<=c)
{    
    system("cls");
		b=50;
        while (b>=a)
{        
			printf(" ");
            b=b-1;
}            
	printf(" O\n");
    
		b=50;
        while (b>=a)
{        
			printf(" ");
            b=b-1;
}            
	printf("<H>\n");
    
		b=50;
        while (b>=a)
{        
			printf(" ");
            b=b-1;
}            
	printf("I I\n");
    a=a+1;
    Sleep(1000);
}    
	system("pause");
	return 0;
}
