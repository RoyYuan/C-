#include<stdio.h> 
#include<string.h> 
int main()
{
	int i,j; 
	char a[101],b[101],*s; 
	scanf("%s %s",a,b); 
	s=strstr(a,b); 
	for(i=0;i<101;i++)
    {
		if(s==&a[i])
        {
			printf("%d\n",i+1);
            return 0;
        }
    } 
	return 0; 
}
