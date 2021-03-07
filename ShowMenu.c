#include<stdio.h>
char showMenu()
{
    char ch;
    do{
        printf("\nA. Commercial Fishing License");
        printf("\nB. Florida Resident Fishing License");
        printf("\nC. Captains Fishing License");
        printf("\nD. Exit Program");
        printf("\nYour choice: ");
        scanf("%s", &ch);
        if(ch == 'A')
            printf("\nUser selected: Commercial Fishing License");
        else if(ch == 'B')
            printf("\nUser selected: Florida Resident Fishing License");
        else if(ch == 'A')
            printf("\nUser selected: Commercial Fishing License");
        else if(ch == 'C')
            printf("\nUser selected: Captains Fishing License");
        else if(ch == 'D')
            printf("\nUser selected: Exit Program");
        else
            printf("\nInvalid Choice !!!!!!");
        printf("\n");
    }while(ch != 'D');
}
int main(){
    showMenu();
    return 0;
}
