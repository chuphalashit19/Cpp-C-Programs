#include<stdio.h>
#include<stdlib.h>

void main() {
    FILE *fp1, *fp2;
    char a;
    const char *fileName="infile.txt";

    fp1 = fopen(fileName,"r");
    if(fp1==NULL){
        printf("Error in opening file.\n");
        return -1;
    }

    fp2 = fopen("outfile.txt", 'w');
    if (fp2 == NULL) {
        puts("Not able to open this file");
        fclose(fp1);
        exit(1);
    }

    do {
        a = fgetc(fp1);
        a = toupper(a);
        fputc(a, fp2);
    }while (a != EOF);
   return 0;
}
