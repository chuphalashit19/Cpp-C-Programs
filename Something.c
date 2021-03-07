#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
   int acc_no;
   char fname[20];
   char lname[20];
   int age;
   char address[20];
   char gender[10];
};
int main () {
   FILE *inf;
   char name[10];
   char option[10];
   int acc_no;
   struct Student inp;
   inf = fopen ("customer.txt", "r");
   if (inf == NULL) {
      fprintf(stderr, "\nError to open the file\n");
      exit (1);
   }
   printf("Choose one, Search By(Name/AccountNo):");
   scanf("%s", option);
   if (option == "Name"){
    while(fread(&inp, sizeof(struct Student), 1, inf))
        scanf("%d %s %s %d %s %s\n", &inp.acc_no, inp.fname, inp.lname, &inp.age, inp.address, inp.gender);
   }

   else if (option == "AccountNo"){
    while(fread(&inp, sizeof(struct Student), 1, inf))
        printf ("AccNO = %d Fname = %s Lname = %s Age = %d Address = %s Gender = %s\n", inp.acc_no, inp.fname, inp.lname, inp.age, inp.address, inp.gender);
   }
   else{
        printf("Wrong option chosen!!!");
   }

   fclose (inf);
}
