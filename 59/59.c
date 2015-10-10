#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a,b,c,d,e,f;
    for(a=1;a<=6;a++)
    {
		for(b=1;b<=6;b++)
        {
			for(c=1;c<=6;c++)
            {
				for(d=1;d<=6;d++)
                {
					for(e=1;e<=6;e++)
                    {
						for(f=1;f<=6;f++)
                        {
							if(a!=b && a!=c && a!=d && a!=e && a!=f 
									&& b!=c && b!=d && b!=e && b!=f 
											&& c!=d && c!=e && c!=f 
													&& d!=e && d!=f 
															&& e!=f )                                                            									                                           																												                                                          
                            {	
                                if(a+b+d==a+c+f && a+c+f==d+e+f)							                                
								{
                                    printf("  %d\n",a);
                                    printf(" %d %d\n",b,c);
                                    printf("%d %d %d\n",d,e,f);  
                                }                              
                            }
                        }
                    }
                }
            }
        }
    }
	system("pause");
	return 0;
}
