#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LEN_NAME 20
#define MAX_GRAD_STUDENTS 5

typedef struct justATag{
    char name[MAX_LEN_NAME];
    char supervisor[MAX_LEN_NAME];
    int numCoursesDone;
    float currentPercentage;
}gradStudent;

void read1Grads(FILE *file, struct justATag gsArray[MAX_GRAD_STUDENTS])
{
    char line[200];
    if (file == NULL)
    {
        printf ( "Could not Open file\n");
        return;
    }
    int i =0;
    while (i<3)
    {
        fgets(line, MAX_LEN_NAME, file);
        strcpy(gsArray[i].name,line);
        fgets(line, MAX_LEN_NAME, file);
        strcpy(gsArray[i].supervisor,line);
        fgets(line, MAX_LEN_NAME, file);
        gsArray[i].numCoursesDone = (int)atoi(line);
        fgets(line, MAX_LEN_NAME, file);
        gsArray[i].currentPercentage = (float)atof(line);
        i++;
    }
    printf(" Grad Student 1 Details:-\n\n");
    for(int i=0; i<3; i++){
        printf(" name: %s supervisor: %s numCoursesDone: %d\n currentPercentage: %.f\n", gsArray[i].name, gsArray[i].supervisor, gsArray[i].numCoursesDone, gsArray[i].currentPercentage);
        printf("\n");
    }
}

void read2Grads(FILE *file, gradStudent gsArray[MAX_GRAD_STUDENTS]){
    int i;
    char line[200];
    if (file == NULL)
    {
        printf ( "could not open file\n");
        return;
    }
     i =0;
    while (i<3)
    {
        fgets(line, 3*MAX_LEN_NAME, file);
        // printf("%s",line);
        char *ptr = strtok(line, " ");      // ptr = Harry
        strcpy(gsArray[i].name,ptr);        //[Harry]
        ptr = strtok(NULL, " ");            // ptr = Dang
        strcat(gsArray[i].name," ");        //[Harry ]
        strcat(gsArray[i].name,ptr);        //[Harry Dang]

        ptr = strtok(NULL, " ");

        strcpy(gsArray[i].supervisor,ptr);
        ptr = strtok(NULL, " ");
        strcat(gsArray[i].supervisor," ");
        strcat(gsArray[i].supervisor,ptr);

        ptr = strtok(NULL, " ");
        gsArray[i].numCoursesDone = (int)atoi(ptr);

        ptr = strtok(NULL, " ");
        gsArray[i].currentPercentage = (float)atof(ptr);
        // printf("poinyt %s",ptr);
        // printf("%s%s%d\n%.f", gsArray[i].name, gsArray[i].supervisor, gsArray[i].numCoursesDone, gsArray[i].currentPercentage);
        i++;
    }
    printf(" Grad Student 2 Details:-\n\n");
    for(i=0; i<3; i++){
        printf(" name: %s\n supervisor: %s\n numCoursesDone: %d\n currentPercentage: %.f\n", gsArray[i].name, gsArray[i].supervisor, gsArray[i].numCoursesDone, gsArray[i].currentPercentage);
        printf("\n");
    }
    fclose (file);
}

int main(){
    gradStudent gsArray[MAX_GRAD_STUDENTS];
    FILE *file;
    file = fopen("gradstudent1.txt", "r");
    read1Grads(file, gsArray);
    printf("\n\n");
    file = fopen("gradstudent2.txt", "r");
    read2Grads(file, gsArray);
}
