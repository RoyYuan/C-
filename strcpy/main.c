#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *cpy(char *a,const char *b)
{
    char *c=a;
    while (*b!='\0')
        *a++=*b++;
    return c;
}


int main()
{
    char a[20],b[20]={"I am a doctor."};
    cpy(a,b);
    puts(a);
    return 0;
}
