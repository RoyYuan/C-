#include <stdio.h>

int main()
{
    int limit,speed;
    printf("Enter the speed limit: ");
    printf("Enter the recorded speed of the car: ");
    scanf("%d%d",&limit,&speed);
    if(limit>=speed)
        printf("Congratulations, you are within the speed limit\n");
    else if(speed-limit>=31)
        printf("You are speeding and your fine is $ 500\n");
    else if(speed-limit<21)
        printf("You are speeding and your fine is $ 100\n");
    else
        printf("You are speeding and your fine is $ 270\n");
    return 0;
}
