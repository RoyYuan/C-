#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char a[5][11],t[11];
    int i,j;
    for(i=0;i<5;i++)
		gets(a[i]);
    for(i=0;i<5;i++)
    {
		for(j=i+1;j<5;j++)
        {
			if(strcmp(a[i],a[j])>0)
			{
                strcpy(t,a[i]);
				strcpy(a[i],a[j]);
				strcpy(a[j],t);
            }
        }
    }
    for(i=0;i<5;i++)
    {
		puts(a[i]);
    }
	system("pause");
	return 0;
}
