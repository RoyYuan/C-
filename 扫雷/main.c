#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 9
int n;                                             //设置的雷数
int num = 0;                                       //被处理过的格子数
char qipan[N][N];                                  //棋盘数组
char lei[N][N] = {0};                              //随机雷区
void init_qipan(char (*p)[N],char (*r)[N]);        //棋盘初始化函数
void init_lei(char (*q)[N]);                       //雷区初始化函数
void scan_lei(int,int);                            //求指定坐标外围雷的个数及显示非雷的格子
void putqipan(void);                               //输出扫描后的棋盘
void lostqipan(void);                              //扫雷失败时输出的棋盘
int main(void)
{
  int row,col;                                     //定义行跟列
  int row1,col1;                                   //定义临时的行跟列变量
  printf("请输入总的雷数：\n");
  scanf("%d",&n);
  init_qipan(qipan,lei);                           //棋盘初始化
  init_lei(lei);                                   //雷区初始化
  do
  {
	   printf("请输入行数（1~9): 列数（1～9）：\n");
	   scanf("%d %d",&row1,&col1);
	   row = row1 - 1;
	   col = col1 - 1;
	   if(lei[row][col]=='#')
	      {
		    printf("You Lost!!!扫雷失败！！！\n");
		    lostqipan();
		    putqipan();
		    break;
	      }
      scan_lei( row, col);
      putqipan();

   } while(N*N-num!=n);
   if(N*N-num==n) printf("You Win!  扫雷成功！\n");
  return 0;
 }


//==================棋盘初始化函数==================
void init_qipan(char (*p)[N],char (*r)[N])
 {
   int i,j;
   int ro = 0,co = 0;
//==================显示行号======================
    printf("    ");
   for(ro = 1;ro <= N;ro++)
      printf("%d    ",ro);
    printf("\n");
    printf("\n");
//==================给棋盘赋初值===================
   for(i = 0;i < N;i++)
     for(j = 0;j < N;j++)
       {
          p[i][j]='*';
         }
//==================显示初始棋盘====================
   for(i = 0;i < N;i++)
     {
       printf("%d   ",++co);                                    //显示列号
       for(j = 0;j < N;j++)
         {
             printf("%c    ",p[i][j]);
           }
       printf("\n");
       printf("\n");
     }
//=================给雷区数组赋初值=================
   for(i = 0;i < N;i++)
     for(j = 0;j < N;j++)
       {
          r[i][j]='0';
         }

 }
//===============随机产生雷区===================
void init_lei(char (*q)[N])
{
  int i,j;
  int row,col;                        //申明行跟列
  srand(time(NULL));
 for(j = 0;j < n;j++)
 {
  row = rand()%N;
  for(i = 0;i < 10000;i++);
  col = rand()%N;
  if(q[row][col]=='#')           //避免在同一个单元内产生雷
     {
        j = j - 1;
       continue;
      }
  q[row][col] = '#';
 }
//===============显示雷区内容==============
 /*for(i = 0;i < N;i++)
       {
         for(j = 0;j < N;j++)
           {
               printf("%c ",q[i][j]);
             }
         printf("\n");
      }*/

}


//========================扫雷函数===========================
void scan_lei(int row,int col)
{

//====================确定指定单元周围雷的个数==========
   if(qipan[row][col]=='*')
    {

       if(row==0&&col==0)                              //判断左上角的格子
         {
          if(lei[0][1]=='#') lei[0][0] = lei[0][0]+1;
          if(lei[1][0]=='#') lei[0][0] = lei[0][0]+1;
          if(lei[1][1]=='#') lei[0][0] = lei[0][0]+1;
          qipan[0][0] = lei[0][0];
          num++;

          }
        else if(row==0&&col==N-1)                       //判断右上角的格子
         {
          if(lei[0][N-2]=='#') lei[0][N-1] = lei[0][N-1]+1;
          if(lei[1][N-1]=='#') lei[0][N-1] = lei[0][N-1]+1;
          if(lei[1][N-2]=='#') lei[0][N-1] = lei[0][N-1]+1;
          qipan[0][N-1] = lei[0][N-1];
          num++;

          }
       else if(row==N-1&&col==0)                       //判断左下角的格子
          {
          if(lei[N-2][0]=='#') lei[N-1][0] = lei[N-1][0]+1;
          if(lei[N-1][1]=='#') lei[N-1][0] = lei[N-1][0]+1;
          if(lei[N-2][1]=='#') lei[N-1][0] = lei[N-1][0]+1;
          qipan[N-1][0] = lei[N-1][0];
          num++;

          }

       else if(row==N-1&&col==N-1)                     //判断右下角的格子
          {
          if(lei[N-2][N-1]=='#') lei[N-1][N-1] = lei[N-1][N-1]+1;
          if(lei[N-1][N-2]=='#') lei[N-1][N-1] = lei[N-1][N-1]+1;
          if(lei[N-2][N-2]=='#') lei[N-1][N-1] = lei[N-1][N-1]+1;
          qipan[N-1][N-1] = lei[N-1][N-1];
          num++;

           }
        else if(col==0&&row!=0&&row!=N-1)               //判断第一列的格子
           {
               if(lei[row-1][col]=='#')   lei[row][col] = lei[row][col]+1;
               if(lei[row-1][col+1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row][col+1]=='#')   lei[row][col] = lei[row][col]+1;
               if(lei[row+1][col+1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row+1][col]=='#')   lei[row][col] = lei[row][col]+1;
               qipan[row][col] = lei[row][col];
               num++;


            }
        else if(col==N-1&&row!=0&&row!=N-1)              //判断最后一列的格子
           {
               if(lei[row-1][col]=='#')   lei[row][col] = lei[row][col]+1;
               if(lei[row-1][col-1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row][col-1]=='#')   lei[row][col] = lei[row][col]+1;
               if(lei[row+1][col-1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row+1][col]=='#')   lei[row][col] = lei[row][col]+1;
               qipan[row][col] = lei[row][col];
               num++;


            }
         else if(row==0&&col!=0&&col!=N-1)               //判断第一行的格子
           {
               if(lei[row][col+1]=='#')   lei[row][col] = lei[row][col]+1;
               if(lei[row+1][col+1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row+1][col]=='#')   lei[row][col] = lei[row][col]+1;
               if(lei[row+1][col-1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row][col-1]=='#')   lei[row][col] = lei[row][col]+1;
               qipan[row][col] = lei[row][col];
               num++;


            }

         else if(row==N-1&&col!=0&&col!=N-1)             //判断最后一行的格子
           {
               if(lei[row][col-1]=='#')   lei[row][col] = lei[row][col]+1;
               if(lei[row-1][col-1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row-1][col]=='#')   lei[row][col] = lei[row][col]+1;
               if(lei[row-1][col+1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row][col+1]=='#')   lei[row][col] = lei[row][col]+1;
               qipan[row][col] = lei[row][col];
               num++;

            }
         else if((0<row&&row<N-1)&&(0<col&&col<N-1))      //中间的格子
            {
               if(lei[row+1][col-1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row][col-1]=='#')   lei[row][col] = lei[row][col]+1;
               if(lei[row-1][col-1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row-1][col]=='#')   lei[row][col] = lei[row][col]+1;
               if(lei[row-1][col+1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row][col+1]=='#')   lei[row][col] = lei[row][col]+1;
               if(lei[row+1][col+1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row+1][col]=='#')   lei[row][col] = lei[row][col]+1;
               qipan[row][col] = lei[row][col];
               num++;


            }
        }
      else return;


//==============================八个方向的递归==========================================

     if(row!=0 && qipan[row][col]=='0')                  scan_lei(row-1,col);
     if(row!=0 && col!=N-1 && qipan[row][col]=='0')      scan_lei(row-1,col+1);
     if(col!=N-1 && qipan[row][col]=='0')                scan_lei(row,col+1);
     if(row!=N-1 && col!=N-1 && qipan[row][col]=='0')    scan_lei(row+1,col+1);
     if(row!=N-1 && qipan[row][col]=='0')                scan_lei(row+1,col);
     if(row!=N-1 && col!=0 && qipan[row][col]=='0')      scan_lei(row+1,col-1);
     if(col!=0 && qipan[row][col]=='0')                  scan_lei(row,col-1);
     if(row!=0 && col!=0 && qipan[row][col]=='0')        scan_lei(row-1,col-1);


}

//=========================扫描后输出棋盘函数===========================
void putqipan(void)
{
  int i,j;
  int ro = 0,co = 0;
//========================显示行号================================
   printf("    ");
   for(ro = 1;ro <= N;ro++)
      printf("%d    ",ro);
    printf("\n");
    printf("\n");
//========================输出扫描后的棋盘======================
  for(i = 0;i < N;i++)
     {
       printf("%d   ",++co);              //显示列号
       for(j = 0;j < N;j++)
         {
             printf("%c    ",qipan[i][j]);
           }
       printf("\n");
       printf("\n");
     }

}
//==================扫雷失败时棋盘显示内容函数==============
void lostqipan(void)
{
   int i,j;
   for(i = 0;i < N;i++)
      for(j = 0;j <N;j++)
          if(lei[i][j]=='#') qipan[i][j] = lei[i][j];

}
