#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_STRING_SIZE 40

int main(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    int i=0, j=0, m=0, n=0, p=0;
    char arr1[10][MAX_STRING_SIZE];
    char arr2[10][MAX_STRING_SIZE];
    char arr3[10][MAX_STRING_SIZE];
    char temp[100];
    fp = fopen("drivers.txt", "r");
    if (fp == NULL)
        printf("\n Empty File!!!\n");

    printf("\n Output:\n\n");
    while ((getline(&line, &len, fp)) != -1) {
        printf(" %s", line);
        if(i != 0 && i < 7){
            int k = 0, l = 0;
            char name[20] = "";
            for(j=0; j<strlen(line); j++){
                if(line[j] != '*'){
                    name[k] = line[j];
                    k++;
                }
                if(line[j] == '*')
                    l++;
                if(l == 3){
                    name[k] = ' ';
                    k++;
                    l=0;
                }
            }
            for(int d=0; d<MAX_STRING_SIZE; d++){
                arr1[m][d] = name[d];
            }
            m++;
        }
        if(i > 7 && i < 12){
            int k = 0, l = 0;
            char name[20] = "";
            for(j=0; j<strlen(line); j++){
                if(line[j] != '*'){
                    name[k] = line[j];
                    k++;
                }
                if(line[j] == '*')
                    l++;
                if(l == 3){
                    name[k] = ' ';
                    k++;
                    l=0;
                }
            }
            for(int d=0; d<MAX_STRING_SIZE; d++){
                arr2[n][d] = name[d];
            }
            n++;
        }
        if(i > 12){
            int k = 0, l = 0;
            char name[20] = "";
            for(j=0; j<strlen(line); j++){
                if(line[j] != '*'){
                    name[k] = line[j];
                    k++;
                }
                if(line[j] == '*')
                    l++;
                if(l == 3){
                    name[k] = ' ';
                    k++;
                    l=0;
                }
            }
            for(int d=0; d<MAX_STRING_SIZE; d++){
                arr3[p][d] = name[d];
            }
            p++;
        }
        i++;
    }
    fclose(fp);

    for(i=0;i<m;i++)
      for(j=i+1;j<m;j++){
         if(strcmp(arr1[i],arr1[j])>0){
            strcpy(temp,arr1[i]);
            strcpy(arr1[i],arr1[j]);
            strcpy(arr1[j],temp);
         }
      }
    for(i=0;i<n;i++)
      for(j=i+1;j<n;j++){
         if(strcmp(arr2[i],arr2[j])>0){
            strcpy(temp,arr2[i]);
            strcpy(arr2[i],arr2[j]);
            strcpy(arr2[j],temp);
         }
      }
    for(i=0;i<p;i++)
      for(j=i+1;j<p;j++){
         if(strcmp(arr3[i],arr3[j])>0){
            strcpy(temp,arr3[i]);
            strcpy(arr3[i],arr3[j]);
            strcpy(arr3[j],temp);
         }
      }
   printf("\n\n After Sort:\n\n");
   printf(" First Track");
   for(i=0;i<m;i++)
      printf(" %s", arr1[i]);

    printf("\n Second Track");
   for(i=0;i<n;i++)
      printf(" %s", arr2[i]);

    printf("\n Third Track\n");
   for(i=0;i<p;i++)
      printf("\n %s", arr3[i]);
}
