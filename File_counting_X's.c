#include <stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
    int i, l, total=0, count, lineno=0;
    char* fileName = "F3file.txt";

    FILE* file = fopen(fileName, "r");

    char line[500];

    while(fgets(line, sizeof(line), file)) {
        count=0;
        for(i=0; i<strlen(line); i++){
            if (line[i] == 'X'){
                count += 1;
            }
        }
        lineno += 1;
        if (count > total){
            l = lineno;
            total = count;
        }
    }
    if (total==0)
        printf("\n Most Xs is 0 on line 0\n");
    else
        printf("\n Most Xs is %d on line %d\n", total, l);

    fclose(file);
    return 0;
}
