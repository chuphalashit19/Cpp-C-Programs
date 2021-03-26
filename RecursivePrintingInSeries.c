#include<stdio.h>

/* Recursive function to print numbers in a given range */

void printNum(int N1, int N2)
{
    if(N1 > N2)
        return;
    else
    {
        printf("%d ", N1);
        N1 += 1;
        return printNum(N1, N2);
    }

}

int main()
{
    int N1, N2;

    scanf("%d", &N1);

    scanf("%d", &N2);

    printNum(N1, N2);
}
