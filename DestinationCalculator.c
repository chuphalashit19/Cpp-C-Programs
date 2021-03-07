#include<stdio.h>

int main()
{
    char *desName;
    int distance;
    float cost;

    printf("\n Enter the destination name: ");
    scanf("%s", desName);
    printf("\n Enter the distance(in kilometers) of the destination: ");
    scanf("%d", &distance);
    if(distance > 0 && distance <= 100){
        cost = 12.5 * (0.6214 * distance);
    }
    else if(distance > 100 && distance <= 500){
        cost = 10.25 * (0.6214 * distance);
    }
    else if(distance > 500 && distance <= 1000){
        cost = 8.5 * (0.6214 * distance);
    }
    else{
        cost = 5 * (0.6214 * distance);
    }
    printf("\n\n -------Details of Travelling-----------");
    printf("\n Name of the Destination: %s", desName);
    printf("\n Cost of Travelling: $%.2f", cost);
    printf("\n ---------------------------------------");
}
