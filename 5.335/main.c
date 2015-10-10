#include <stdio.h>
#include <stdlib.h>

int main()
{
    double e,s=1;
    int n;
    for(n=1;n>0;n++)
    {
        s/=n;
        if(s>1E-7)
        {
            e+=s;
        }
        else
        {
            break;
        }
    }
    printf("eµÄÖµÎª%lf\n",e);

    return 0;
}
