#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
int MAP[4][4],gre;
int add(int n)
{
srand((unsigned int)time(0));
int num = rand();
int tf = num % 2;
int x,y,i;
x = num % 4;
srand((unsigned int)time(0) + (unsigned int)num);
y = rand();
y %= 4;
if (tf)
num = 2;
else
num = 4;
if (n == 0)
{
MAP[x][y] = num;
}
else if (n == 1)
{
if (MAP[3][y] == 0)
MAP[3][y] = num;
else
for (i = 0; i < 4; i++)
if (MAP[3][i] == 0)
{
MAP[3][i] = num;
break;
}
}
else if (n == 2)
{
if (MAP[0][y] == 0)
MAP[0][y] = num;
else
for (i = 0; i < 4; i++)
if (MAP[0] == 0)
{
MAP[0] = num;
break;
}
}
else if (n == 3)
{
if (MAP[x][3] == 0)
MAP[x][3] = num;
else
for (i = 0; i < 4; i++)
if (MAP[3] == 0)
{
MAP[3] = num;
break;
}
}
else if (n == 4)
{
if (MAP[x][0] == 0)
MAP[x][0] = num;
else
for (i = 0; i < 4; i++)
if (MAP[0] == 0)
{
MAP[0] = num;
break;
}
}
}
int movup(void)
{
int i,k,t;
int tf = 0;
for (k = 0; k < 4; k++)
{
int n = 4;
while (n--)
for (i = 0; i < 3; i++)
if (MAP[k] == 0)
{
for (t = i; t < 3; t++)
{
MAP[t][k] = MAP[t + 1][k];
MAP[t + 1][k] = 0;
tf = 1;
}
}
for (i = 0; i < 3; i++)
{
if (MAP[k] == MAP[k])
{
MAP[k] *= 2;
gre += MAP[k];
if (MAP[k] == 2048)
return 0;
for (t = i + 1; t < 3; t++)
{
MAP[t][k] = MAP[t + 1][k];
MAP[t + 1][k] = 0;
tf = 1;
}
}
}
}
if (tf)
add(1);
return 1;
}
int movdow(void)
{
int i,k,t;
int tf = 0;
for (k = 0; k < 4; k++)
{
int n = 4;
while (n--)
for (i = 3; i > 0; i--)
if (MAP[k] == 0)
{
for (t = i; t > 0; t--)
{
MAP[t][k] = MAP[t - 1][k];
MAP[t - 1][k] = 0;
tf = 1;
}
}
for (i = 3; i > 0; i--)
{
if (MAP[k] == MAP[k])
{
MAP[k] *= 2;
gre += MAP[k];
if (MAP[k] == 2048)
return 0;
for (t = i - 1; t > 0; t--)
{
MAP[t][k] = MAP[t - 1][k];
MAP[t - 1][k] = 0;
tf = 1;
}
}
}
}
if (tf)
add(2);
return 1;
}
int movlif(void)
{
int i,k,t;
for (i = 0; i < 4; i++)
{
int n = 4;
while (n--)
for (k = 0; k < 3; k++)
{
if(MAP[k] == 0)
for (t = k; t < 3; t++)
{
MAP[t] = MAP[t + 1];
MAP[t + 1] = 0;
}
}
for (k = 0;k < 3;k++)
{
if (MAP[k] == MAP[k + 1])
{
MAP[k] *= 2;
gre += MAP[k];
if (MAP[k] == 2048)
return 0;
for (t = k + 1; t < 3; t++)
{
MAP[t] = MAP[t + 1];
MAP[t + 1] = 0;
}
}
}
}
add(3);
return 1;
}
int movri(void)
{
int i,k,t;
for (i = 0; i < 4; i++)
{
int n = 4;
while (n--)
for (k = 3; k > 0; k--)
{
if(MAP[k] == 0)
for (t = k; t > 0; t--)
{
MAP[t] = MAP[t - 1];
MAP[t - 1] = 0;
}
}
for (k = 3;k > 0;k--)
{
if (MAP[k] == MAP[k - 1])
{
MAP[k] *= 2;
gre += MAP[k];
if (MAP[k] == 2048)
return 0;
for (t = k - 1; t > 0; t--)
{
MAP[t] = MAP[t - 1];
MAP[t - 1] = 0;
}
}
}
}
add(4);
return 1;
}
int mov(void)
{
fflush(stdin);
char key;
key = getch();
int tf = 1;
if (key == 72)
tf = movup();
else if (key == 80)
tf = movdow();
else if (key == 75)
tf = movlif();
else if (key == 77)
tf = movri();
if (!tf)
{
system("CLS");
printf ("��ϲ�ﵽ2048��\n");
}
return tf;
}
int pd (void)
{
int i,k;
for (i = 0; i < 4; i++)
{
for (k = 1; k < 4; k++)
if (MAP[k - 1] == MAP[k])
return 0;
}
for (i = 0; i < 4; i++)
{
for (k = 1; k < 4; k++)
if (MAP[k - 1] == MAP[k])
return 0;
}
system("CLS");
printf ("��Ϸ������\n");
return 1;
}
int pri (void)
{
printf ("�÷֣�%d\n",gre);
printf ("\t�������ש����ש����ש�����\n");
printf ("\t��%4d��%4d��%4d��%4d��\n",MAP[0][0],MAP[0][1],MAP[0][2],MAP[0][3]);
printf ("\t�ǩ����贈���贈���贈����\n");
printf ("\t��%4d��%4d��%4d��%4d��\n",MAP[1][0],MAP[1][1],MAP[1][2],MAP[1][3]);
printf ("\t�ǩ����贈���贈���贈����\n");
printf ("\t��%4d��%4d��%4d��%4d��\n",MAP[2][0],MAP[2][1],MAP[2][2],MAP[2][3]);
printf ("\t�ǩ����贈���贈���贈����\n");
printf ("\t��%4d��%4d��%4d��%4d��\n",MAP[3][0],MAP[3][1],MAP[3][2],MAP[3][3]);
printf ("\t�������ߩ����ߩ����ߩ�����\n");
}
int main()
{
int i;
system("COLOR 3B");
printf ("\n\t��2048������̨��\n\n");
printf ("��Ϸ������ͬ�����Σ���\n");
printf ("\t��ʼ�����ڻ����2����4��������С���֣�\n");
printf ("\t���ֻ��Ҫ�������ң���������ƣ�����һ���������ƶ����ֵ����֣�\n");
printf ("\t���е����־ͻ��򻬶��ķ���£��\n");
printf ("\t�������Ŀհ׷���ͻ��������һ�����֣�\n");
printf ("\t��ͬ��������ײʱ����ӿ�£��\n");
printf ("\tȻ��һֱ���������ϵĵ�������ƴ�ճ�2048������־���ɹ���\n");
printf ("\n\n!������������ַ���ʼ��Ϸ!\n�����齫����̨����Ϊ�����壩\n");
char s[100];
while (scanf ("%s",s),strcmp(s,"0"))
{
memset (MAP,0,sizeof (MAP));
gre = 0;
system("CLS");
add(0);
pri();
while (mov())
{
fflush(stdin);
system("CLS");
pri();
if (pd())
break;
}
printf ("���μ�����Ϸ������0�˳�����\n");
}
return 0
