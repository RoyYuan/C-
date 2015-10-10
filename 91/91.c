#include <stdio.h>
#include <stdlib.h>
int main()
{
	char a[50][50]={"######",
					"#O #  ",
                    "# ## #",
                    "#  # #",
                    "##   #",
                    "######",};
	int i,x=1,y=1,p=1,q=5;
	char ch;
    for(i=0;i<=5;i++)
		puts(a[i]);
	while(1)
	{
		ch=getch();
		if(ch=='s')
		{
			if(a[x+1][y]!='#')
			{
				a[x][y]=' ';
				x++;
				a[x][y]='O';
			}
		}
    
		system("cls");
		for(i=0;i<=5;i++)
		{
			puts(a[i]);
		}
    }
	system("pause");
	return 0;
}
