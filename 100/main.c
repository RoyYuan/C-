#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int s[100001],n,i;

int cmp(const void *a, const void *b)
{
	return(*(int *)a-*(int *)b);
}

int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++) 
		scanf("%d",&s[i]);
	qsort(s,n,sizeof(s[0]),cmp);
	for(i=0;i<n;i++) 
		printf("%d ",s[i]);
	return 0;
}
