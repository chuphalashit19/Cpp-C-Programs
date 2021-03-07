#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float add(float a, float b){
    return a+b;
}

float sub(float a, float b){
    return a-b;
}

float division(float a, float b){
    return a/b;
}

float mul(float a, float b){
    return a*b;
}

float max(float a, float b){
    if (a>b)
        return a;
    else
        return b;
}

float min(float a, float b){
    if(a<b)
        return a;
    else
        return b;
}

float sqroot(float a){
    return sqrt(a);
}

float square(float a){
    return(a*a);
}
int main(){
    int i=0, k;
    float a, b, res, arr[100] ;
    char ch = '0';
    while(1){
        printf("\n Welcome to the Calculator\n");
        printf(" 1. Addition\n");
        printf(" 2. Subtraction\n");
        printf(" 3. Multiplication\n");
        printf(" 4. Division\n");
        printf(" 5. Maximum(a,b)\n");
        printf(" 6. Minimum(a,b)\n");
        printf(" 7. Square Root(a)\n");
        printf(" 8. Square(a)\n");
        printf(" M. Select M to see the memory\n");
        printf(" R. Select R to erase the memory\n");
        printf(" 9. Exit");
        printf("\n Enter your choice: ");
        scanf("%s", &ch);
        if (ch == '1'){
                printf("\n\t Enter two values to add: ");
                scanf("%f %f", &a, &b);
                res = add(a, b);
                arr[i] = res;
                i++;
        }
        else if (ch == '2'){
                printf("\n\t Enter two values to subtract: ");
                scanf("%f %f", &a, &b);
                res = sub(a, b);
                arr[i] = res;
                i++;
        }
        else if(ch == '3'){
                printf("\n\t Enter two values to multiply: ");
                scanf("%f %f", &a, &b);
                res = mul(a, b);
                arr[i] = res;
                i++;
        }
        else if(ch == '4'){
                printf("\n\t Enter two values to divide: ");
                scanf("%f %f", &a, &b);
                while(b == 0){
                    printf("\n\n\t Value of b cannot be zero!!");
                    printf("\n\t Enter the value for b again:");
                    scanf("%d", &b);
                }
                res = division(a, b);
                arr[i] = res;
                i++;
        }
        else if(ch == '5'){
                printf("\n\t Enter two values to find the maximum: ");
                scanf("%f %f", &a, &b);
                res = max(a, b);
                arr[i] = res;
                i++;
        }
        else if(ch == '6'){
                printf("\n\t Enter two values to find the minimum: ");
                scanf("%f %f", &a, &b);
                res = min(a, b);
                arr[i] = res;
                i++;
        }
        else if(ch == '7'){
                printf("\n\t Enter a value to find the square root: ");
                scanf("%f", &a);
                res = sqroot(a);
                arr[i] = res;
                i++;
        }
        else if(ch == '8'){
                printf("\n\t Enter a value to find the sqaure: ");
                scanf("%f", &a);
                res = square(a);
                arr[i] = res;
                i++;
        }

        else if (ch == 'M'){
            if (i == 0){
                printf("\n\t The memory is empty!!!\n");
            }
            else{
                char ch1;
                do{
                    printf("\n\n\t There are %d items available in the memory", i);
                    printf("\n\n\t 1)Press 0 to print the whole memory");
                    printf("\n\t 2)Choose any items in range 1 to %d", i);
                    printf("\n\t 3)Enter E to go back to main menu");
                    printf("\n\n\t Your choice: ");
                    scanf("%s", &ch1);
                    if (ch1 == '0'){
                        printf("\n\t Memory contains following values: ");
                        for(k = 0; k<i; k++){
                            printf("%.7g\t", arr[k]);
                        }
                    }
                    else if (ch1 != 'E'){
                        int y = ch1 - '0';
                        printf("\n\t The value: %.7g", arr[y-1]);
                    }
                }while(ch1 != 'E');
            }
        }
        else if(ch == 'R'){
            for (k=0; k<i; k++)
            {
                arr[k] = '\0';
            }
            i = 0;
            printf("\n\tMemory erased !!!\n");
        }
        else if(ch == '9'){
            printf("\n**********Exiting from calculator**********\n");
            break;
        }
    }
}
