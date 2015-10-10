#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 9
int n;                                             //���õ�����
int num = 0;                                       //��������ĸ�����
char qipan[N][N];                                  //��������
char lei[N][N] = {0};                              //�������
void init_qipan(char (*p)[N],char (*r)[N]);        //���̳�ʼ������
void init_lei(char (*q)[N]);                       //������ʼ������
void scan_lei(int,int);                            //��ָ��������Χ�׵ĸ�������ʾ���׵ĸ���
void putqipan(void);                               //���ɨ��������
void lostqipan(void);                              //ɨ��ʧ��ʱ���������
int main(void)
{
  int row,col;                                     //�����и���
  int row1,col1;                                   //������ʱ���и��б���
  printf("�������ܵ�������\n");
  scanf("%d",&n);
  init_qipan(qipan,lei);                           //���̳�ʼ��
  init_lei(lei);                                   //������ʼ��
  do
  {
	   printf("������������1~9): ������1��9����\n");
	   scanf("%d %d",&row1,&col1);
	   row = row1 - 1;
	   col = col1 - 1;
	   if(lei[row][col]=='#')
	      {
		    printf("You Lost!!!ɨ��ʧ�ܣ�����\n");
		    lostqipan();
		    putqipan();
		    break;
	      }
      scan_lei( row, col);
      putqipan();

   } while(N*N-num!=n);
   if(N*N-num==n) printf("You Win!  ɨ�׳ɹ���\n");
  return 0;
 }


//==================���̳�ʼ������==================
void init_qipan(char (*p)[N],char (*r)[N])
 {
   int i,j;
   int ro = 0,co = 0;
//==================��ʾ�к�======================
    printf("    ");
   for(ro = 1;ro <= N;ro++)
      printf("%d    ",ro);
    printf("\n");
    printf("\n");
//==================�����̸���ֵ===================
   for(i = 0;i < N;i++)
     for(j = 0;j < N;j++)
       {
          p[i][j]='*';
         }
//==================��ʾ��ʼ����====================
   for(i = 0;i < N;i++)
     {
       printf("%d   ",++co);                                    //��ʾ�к�
       for(j = 0;j < N;j++)
         {
             printf("%c    ",p[i][j]);
           }
       printf("\n");
       printf("\n");
     }
//=================���������鸳��ֵ=================
   for(i = 0;i < N;i++)
     for(j = 0;j < N;j++)
       {
          r[i][j]='0';
         }

 }
//===============�����������===================
void init_lei(char (*q)[N])
{
  int i,j;
  int row,col;                        //�����и���
  srand(time(NULL));
 for(j = 0;j < n;j++)
 {
  row = rand()%N;
  for(i = 0;i < 10000;i++);
  col = rand()%N;
  if(q[row][col]=='#')           //������ͬһ����Ԫ�ڲ�����
     {
        j = j - 1;
       continue;
      }
  q[row][col] = '#';
 }
//===============��ʾ��������==============
 /*for(i = 0;i < N;i++)
       {
         for(j = 0;j < N;j++)
           {
               printf("%c ",q[i][j]);
             }
         printf("\n");
      }*/

}


//========================ɨ�׺���===========================
void scan_lei(int row,int col)
{

//====================ȷ��ָ����Ԫ��Χ�׵ĸ���==========
   if(qipan[row][col]=='*')
    {

       if(row==0&&col==0)                              //�ж����Ͻǵĸ���
         {
          if(lei[0][1]=='#') lei[0][0] = lei[0][0]+1;
          if(lei[1][0]=='#') lei[0][0] = lei[0][0]+1;
          if(lei[1][1]=='#') lei[0][0] = lei[0][0]+1;
          qipan[0][0] = lei[0][0];
          num++;

          }
        else if(row==0&&col==N-1)                       //�ж����Ͻǵĸ���
         {
          if(lei[0][N-2]=='#') lei[0][N-1] = lei[0][N-1]+1;
          if(lei[1][N-1]=='#') lei[0][N-1] = lei[0][N-1]+1;
          if(lei[1][N-2]=='#') lei[0][N-1] = lei[0][N-1]+1;
          qipan[0][N-1] = lei[0][N-1];
          num++;

          }
       else if(row==N-1&&col==0)                       //�ж����½ǵĸ���
          {
          if(lei[N-2][0]=='#') lei[N-1][0] = lei[N-1][0]+1;
          if(lei[N-1][1]=='#') lei[N-1][0] = lei[N-1][0]+1;
          if(lei[N-2][1]=='#') lei[N-1][0] = lei[N-1][0]+1;
          qipan[N-1][0] = lei[N-1][0];
          num++;

          }

       else if(row==N-1&&col==N-1)                     //�ж����½ǵĸ���
          {
          if(lei[N-2][N-1]=='#') lei[N-1][N-1] = lei[N-1][N-1]+1;
          if(lei[N-1][N-2]=='#') lei[N-1][N-1] = lei[N-1][N-1]+1;
          if(lei[N-2][N-2]=='#') lei[N-1][N-1] = lei[N-1][N-1]+1;
          qipan[N-1][N-1] = lei[N-1][N-1];
          num++;

           }
        else if(col==0&&row!=0&&row!=N-1)               //�жϵ�һ�еĸ���
           {
               if(lei[row-1][col]=='#')   lei[row][col] = lei[row][col]+1;
               if(lei[row-1][col+1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row][col+1]=='#')   lei[row][col] = lei[row][col]+1;
               if(lei[row+1][col+1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row+1][col]=='#')   lei[row][col] = lei[row][col]+1;
               qipan[row][col] = lei[row][col];
               num++;


            }
        else if(col==N-1&&row!=0&&row!=N-1)              //�ж����һ�еĸ���
           {
               if(lei[row-1][col]=='#')   lei[row][col] = lei[row][col]+1;
               if(lei[row-1][col-1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row][col-1]=='#')   lei[row][col] = lei[row][col]+1;
               if(lei[row+1][col-1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row+1][col]=='#')   lei[row][col] = lei[row][col]+1;
               qipan[row][col] = lei[row][col];
               num++;


            }
         else if(row==0&&col!=0&&col!=N-1)               //�жϵ�һ�еĸ���
           {
               if(lei[row][col+1]=='#')   lei[row][col] = lei[row][col]+1;
               if(lei[row+1][col+1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row+1][col]=='#')   lei[row][col] = lei[row][col]+1;
               if(lei[row+1][col-1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row][col-1]=='#')   lei[row][col] = lei[row][col]+1;
               qipan[row][col] = lei[row][col];
               num++;


            }

         else if(row==N-1&&col!=0&&col!=N-1)             //�ж����һ�еĸ���
           {
               if(lei[row][col-1]=='#')   lei[row][col] = lei[row][col]+1;
               if(lei[row-1][col-1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row-1][col]=='#')   lei[row][col] = lei[row][col]+1;
               if(lei[row-1][col+1]=='#') lei[row][col] = lei[row][col]+1;
               if(lei[row][col+1]=='#')   lei[row][col] = lei[row][col]+1;
               qipan[row][col] = lei[row][col];
               num++;

            }
         else if((0<row&&row<N-1)&&(0<col&&col<N-1))      //�м�ĸ���
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


//==============================�˸�����ĵݹ�==========================================

     if(row!=0 && qipan[row][col]=='0')                  scan_lei(row-1,col);
     if(row!=0 && col!=N-1 && qipan[row][col]=='0')      scan_lei(row-1,col+1);
     if(col!=N-1 && qipan[row][col]=='0')                scan_lei(row,col+1);
     if(row!=N-1 && col!=N-1 && qipan[row][col]=='0')    scan_lei(row+1,col+1);
     if(row!=N-1 && qipan[row][col]=='0')                scan_lei(row+1,col);
     if(row!=N-1 && col!=0 && qipan[row][col]=='0')      scan_lei(row+1,col-1);
     if(col!=0 && qipan[row][col]=='0')                  scan_lei(row,col-1);
     if(row!=0 && col!=0 && qipan[row][col]=='0')        scan_lei(row-1,col-1);


}

//=========================ɨ���������̺���===========================
void putqipan(void)
{
  int i,j;
  int ro = 0,co = 0;
//========================��ʾ�к�================================
   printf("    ");
   for(ro = 1;ro <= N;ro++)
      printf("%d    ",ro);
    printf("\n");
    printf("\n");
//========================���ɨ��������======================
  for(i = 0;i < N;i++)
     {
       printf("%d   ",++co);              //��ʾ�к�
       for(j = 0;j < N;j++)
         {
             printf("%c    ",qipan[i][j]);
           }
       printf("\n");
       printf("\n");
     }

}
//==================ɨ��ʧ��ʱ������ʾ���ݺ���==============
void lostqipan(void)
{
   int i,j;
   for(i = 0;i < N;i++)
      for(j = 0;j <N;j++)
          if(lei[i][j]=='#') qipan[i][j] = lei[i][j];

}
