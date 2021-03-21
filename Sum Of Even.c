#include<stdio.h>

int main(){
    int arr[100] = {0};
    int num = 0, sum =0, i = 0, j;
    do{
        printf("Enter a number: ");
        scanf("%d", &num);
        if(num > 0){
            sum += num;
            if(num % 2 == 0)
            {
                arr[i] = num;
                i++;
            }
        }
    }while(num >= 0);

    printf("\nSum of all numbers: %d\n", sum);
    printf("\nPrinting all even numbers: ");

    for(j=0; j<i; j++){
        printf("%d ", arr[j]);
    }
    printf("\n\n");
    return 0;
}
