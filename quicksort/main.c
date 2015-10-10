#include <stdio.h>

int a[100];

void swap(int *a,int *b)
{
    *a+=*b;
    *b=*a-*b;
    *a-=*b;
}

void quicksort(int left,int right)
{
    if(left>right)
        return;
    int i,j;
    i=left;
    j=right;
    while(i!=j)
    {
        while(j>i && a[j]<=a[left])
            j--;
        while(i<j && a[i]>=a[left])
            i++;
        if(i<j)
            swap(&a[i],&a[j]);
    }
    if(i!=left)
        swap(&a[i],&a[left]);
    quicksort(left,i-1);
    quicksort(i+1,right);
}

int main()
{
    int i=0,j;
    while(scanf("%d",&a[i])==1 && i<10)
        i++;
    quicksort(0,i-1);
    for(j=0;j<i;j++)
        printf("%d ",a[j]);
    return 0;
}


