#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

findPalind(char *arr,int s)
{
    int flag = 0,i,j,m,n;
    for(i=0;i<s;i++)
    {
       for(j=i+2;j<s;j++)
        {
            for(m=i;m<j;m++)
            {
                n=j-m+i;
                if(*(arr+m)==*(arr+n))
                    flag=1;
                else
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        if(flag==1)
            break;
    }
    if (flag==1)
        printf("YES\n");
    else
        printf("NO\n");
    return;
}
int main()
{
    char arr[100001]={0};
    int i=0;
    scanf("%s",arr);
    while(arr[i]>=97&&arr[i]<=122)
    {
        i++;
    }
    findPalind(&arr,i);
    return 0;
}
