#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define H struct plas

typedef int Bool;

int n,sum=0;

struct plas
{
	int x;
	int y;
}wt[8],blk[8];

Bool t[8][8];
Bool s[8][8];


int f(H a,H b)
{
	if(a.x==b.x)
		return 1;
	if(a.y==b.y)
		return 1;
	if(abs(a.x-b.x)==abs(a.y-b.y))
		return 1;
	return 0;
}

void dfs1(int k)
{
	int i,j,flag=0;
	void dfs2();
	if(k==n)
	{
		dfs2(0);
		return ;
	}
	for(i=0;i<n;i++)
	{
		flag=0;
		if(t[k][i] && !s[k][i])
		{
			wt[k].x=k;
			wt[k].y=i;
			s[k][i]=1;
			for(j=0;j<k;j++)
			{
				if(f(wt[k],wt[j]))
				{
					flag=1;
					break;
				}
			}
			if(flag)
			{
				s[k][i]=0;
				continue;
			}
			else
			{
				dfs1(k+1);
				s[k][i]=0;
			}
		}
	}
}

void dfs2(int k)
{
	int i,j,flag;
	if(k==n)
	{
		sum++;
		return ;
	}
	for(i=0;i<n;i++)
	{
		flag=0;
		if(t[k][i] && !s[k][i])
		{
			blk[k].x=k;
			blk[k].y=i;
			s[k][i]=1;
			for(j=0;j<k;j++)
			{
				if(f(blk[k],blk[j]))
				{
					flag=1;
					break;
				}
			}
			if(flag)
			{
				s[k][i]=0;
				continue;
			}
			else
			{
				dfs2(k+1);
				s[k][i]=0;
			}
		}
	}
}



int main()
{
	int i,j;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		memset(s,0,8*8*sizeof(int));
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&t[i][j]);
		dfs1(0);
		printf("%d\n",sum);
	}
	return 0;
}
