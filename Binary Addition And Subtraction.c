#include <stdio.h>

int binaryAdd(int num1, int num2)
{
    int carry;
    while (num2 != 0) {
        //finding carry and then applying left shift to it
        carry = (num1 & num2) << 1;

        //find the sum
        num1 = num1^num2;
        num2 = carry;
    }
    return num1;
}

int binarySubtract(int num1, int num2)
{
    int carry;
    // ~num2 = 1's Complement of num2
    // adding 1 to num2 to make it 2's compliment
    carry = num1 + (~num2 + 1);
    return carry;
}

int main()
{
    int num1,num2, bAdd, bSubtract;
    printf("\n Enter first value: ");
    scanf(" %d",&num1);
    printf("\n Enter second value: ");
    scanf(" %d",&num2);
    bAdd = binaryAdd(num1,num2);
    bSubtract = binarySubtract(num1,num2);
    printf("\n\n Binary Addition: %d\n",bAdd);
    printf("\n\n Binary Subtraction: %d\n",bSubtract);
    return 0;
}
