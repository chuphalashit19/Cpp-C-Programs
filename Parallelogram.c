#include <stdio.h>

int main()
{
    int i, j, k, height, width=10;

    /* Inputting height from user */
    printf("Enter height in the range(1-10): ");
    scanf("%d", &height);

    for(i=1; i<=height; i++)
    {
        /* Print # up to given width */
        for(j=1; j<=width; j++)
        {
            printf("#");
        }

        /* Moving to next line */
        printf("\n");

        /* Print spaces */
        for(k=1; k<=i; k++)
        {
            printf(" ");
        }
    }
}
