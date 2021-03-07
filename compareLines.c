#include<stdio.h>
#include<string.h>

int compareLines(char line1[], char line2[]){
    int c1 = 0;
    int c2 = 0;
    for(int i=0; line1[i] != '\0'; i++)
        c1 = c1 + 1;
    for(int i=0; line2[i] != '\0'; i++)
        c2 = c2 + 1;

    if(c1 > c2)
        return 1;
    else if(c1 < c2)
        return -1;
}

int main(void){
    char line1[] = "Hello I am Vishal from Bangalore";
    char line2[] = "I do not like the behaviour of Vishal";
    printf("\n Answer: %d", compareLines(line1, line2));
    printf("\n");
    printf("\n Answer: %d", compareLines(line2, line1));
    printf("\n");
}
