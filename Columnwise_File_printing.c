#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char* tp, date, symbol;
    float open, high, low, close, vbtc, vusd;
} record;

int main(void) {
    char ch[1000];
    FILE *fp;
    record rec[10];
    int c = 0;

    fp = fopen("column_wise.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error reading file\n");
        return 1;
    }

    fscanf(fp, "%[^\n]", ch);
    printf("Data from the file:\n%s", ch);

    while (fscanf(fp, "%s, %s, %s, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f", &rec[c].tp, &rec[c].date, &rec[c].symbol, &rec[c].open, &rec[c].high, &rec[c].low, &rec[c].close, &rec[c].vbtc, &rec[c].vusd)  == 9) {
        c++;
    }
    printf("Line:- %d", c);

    for (int i = 0; i < c; i++) {
        printf(" %s, %s, %s, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f", rec[i].tp, rec[i].date, rec[i].symbol, rec[i].open, rec[i].high, rec[i].low, rec[i].close, rec[i].vbtc, rec[i].vusd);
        printf("\n");
    }

    fclose(fp);

    return 0;
}
