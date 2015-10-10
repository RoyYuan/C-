#include <stdio.h>

#define f(a,b) a##b
#define g(a) #a
#define d(a) g(a)

int main()
{
    printf("%s\n",d(f(a,b)));
    printf("%s\n",g(f(a,b)));
    return 0;
}
