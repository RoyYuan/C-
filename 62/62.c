#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int a;
    srand((unsigned)time(NULL));
    a=rand()%20000001;
    printf("%d",a);
	system("pause");
	return 0;
}
