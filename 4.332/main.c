//����1��100֮���������Լ�ż����
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,ji=0,ou=0;
    for(x=1;x<=100;x+=2)
    {
        ji+=x;
    }
    for(x=2;x<=100;x+=2)
    {
        ou+=x;
    }
    printf("1��100��������Ϊ%d��ż����Ϊ%d",ji,ou);
    return 0;
}
