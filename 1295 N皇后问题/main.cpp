#include <stdio.h>
#include <stdlib.h>
#define H struct coordinate

bool s[15][15];
int n;
int sum;

struct coordinate
{
    int x;
    int y;
}wt[15];

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

void dfs(int k)
{
	int i,j,flag=0;
	if(k==n)
	{
	    sum++;
		return ;
	}
	for(i=0;i<n;i++)
	{
		flag=0;
		if(!s[k][i])
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
				dfs(k+1);
				s[k][i]=0;
			}
		}
	}
}

int main()
{
    scanf("%d",&n);
    dfs(0);
    printf("%d\n",sum);
    return 0;
}
