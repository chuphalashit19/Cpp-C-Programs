#include<stdio.h>
#include <stdlib.h>
#include <string.h>
struct cust
{
   int acc_no;
   char fname[20];
   char lname[20];
   int age;
   char address[20];
   char gender[10];
};

int main(){
    FILE *file;
    struct cust input;
    file = fopen ("customer.txt", "r");
    if (file == NULL)
    {
        fprintf(stderr, "\nError opening file\n");
        exit (1);
    }

    while(fread(&input, sizeof(struct cust), 1, file)){
        printf("1");
        printf("%d %s %d %s %s\n", input.acc_no, input.fname, input.lname, input.age, input.address, input.gender);
    }
    // close file
    fclose(file);
}
