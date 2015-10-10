#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main()
{
	system("shutdown -s -t 50");
    Sleep(10000);
    system("shutdown -a");
	system("pause");
	return 0;
}
