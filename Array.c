#include<stdio.h>

int numOfEvenValues(int arr[10])
{
    int i, count=0;
    for(i=0; i<10; i++)
    {
        if (arr[i] % 2 == 0)
            count += 1;
    }
    return count;
}

int main(void){
    int arr[10];
    int i, cnt;

    printf("\n Enter the 10 array values: ");

    for(i=0; i<10; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n Array elements entered:\n");
    for(i=0; i<10; i++)
    {
        printf(" Array value%d: %d\n", i+1, arr[i]);
    }
    cnt = numOfEvenValues(arr);
    printf("\n Total number of even values in Array: %d", cnt);
    printf("\n\n");
}
