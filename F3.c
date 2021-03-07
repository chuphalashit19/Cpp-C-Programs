#include <stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
    int i, l, total=0, count, lineno=0;
    int line_buf_size = 0;
    int line_size;
    char* fileName = "F3file.txt";
    char* line = NULL;

    FILE* file = fopen(fileName, "r");
    line_size = getline(&line, &line_buf_size, file);

    while (line_size >= 0) {
        int len = strlen(line);
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
        line_size = getline(&line, &line_buf_size, file);
    }
    fclose(file);
    if (total==0)
        printf("\n Most Xs is 0 on line 0\n");
    else
        printf("\n Most Xs is %d on line %d\n", total, l);


    return 0;
}
