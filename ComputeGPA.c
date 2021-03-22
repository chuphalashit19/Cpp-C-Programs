#include<stdio.h>
void main(void)
{
    float grade1=0;
    float grade2=0;
    float grade3=0;
    float grade4=0;
    float GPA=0;

    /*This line is used to remind user to input grades*/
    printf("\nPlease input Tom's 4 grades:\n");
    scanf_s("%f %f %f %f", &grade1, &grade2, &grade3, &grade4);
    GPA = (grade1+grade2+grade3+grade4)/4;
    printf("Tom's GPA is: %.2f.", GPA);

    //open  the file TomGrade.txt using write mode 'w'
    FILE *fp = fopen("TomGrade.txt", "w");
    if (fp == NULL)
    {
        printf("\nError opening the file!!\n\n");
        return;
    }
    fprintf(fp, "Grade1\tGrade2\tGrade3\tGrade4\tAverage(GPA)\n");
    fprintf(fp, "%.2f\t%.2f\t%.2f\t%.2f\t%.2f", grade1, grade2, grade3, grade4, GPA);
    fclose(fp);
    printf("\n\n");
}
