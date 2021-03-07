#include<stdio.h>

int main(){
    int ch, ch1;
    char choice;
    float b, h, a1, a2, a3, side, area, perimeter;

    printf("\n        =============================================================\n");
    printf("                    WELCOME TO SHAPE CALCULATION SYSTEM              \n");
    printf("        =============================================================\n\n");
    do{
        printf("\nChoose the shape below by entering the shape code [1/2] :");
        printf("\n1.  TRIANGLE");
        printf("\n2.  SQUARE");
        printf("\nPlease enter your choice : ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("\nPlease select the type of calculation [1/2] :");
                printf("\n1.  AREA");
                printf("\n2.  PERIMETER");
                printf("\nEnter the type of calculation [1/2]: ");
                scanf("%d", &ch1);

                if (ch1 == 1){
                    printf("\n+++++++++++TRIANGLE AREA+++++++++++++");
                    printf("\nPlease enter the base (cm): ");
                    scanf("%f", &b);
                    printf("Please enter the height (cm): ");
                    scanf("%f", &h);
                    area = 0.5 * b * h;
                    printf("\n+++++++++++Result of Calculation+++++++++++++");
                    printf("\nArea: %.2f", area);
                    printf("\n\nDo you want to continue (Y/N) : ");
                    scanf("%s", &choice);
                    if (choice == 'Y')
                        break;
                    else{
                        printf("\n\n+++++++++++EXITING++++++++++++++++++++\n\n");
                        return 0;
                    }

                }
                else if(ch1 == 2){
                    printf("\n+++++++++++TRIANGLE PERIMETER+++++++++++++");
                    printf("\nPlease enter the side a (cm): ");
                    scanf("%f", &a1);
                    printf("\nPlease enter the side b (cm): ");
                    scanf("%f", &a2);
                    printf("\nPlease enter the side b (cm): ");
                    scanf("%f", &a3);
                    perimeter = a1 + a2 + a3;
                    printf("\n+++++++++++Result of Calculation+++++++++++++");
                    printf("\nPerimeter: %.2f", perimeter);
                    printf("\n\nDo you want to continue (Y/N) : ");
                    scanf("%s", &choice);
                    if (choice == 'Y')
                        break;
                    else{
                        printf("\n\n+++++++++++EXITING++++++++++++++++++++\n\n");
                        return 0;
                    }
                }
                else{
                    printf("\n\n+++++++++++EXITING++++++++++++++++++++\n\n");
                    return 0;
                }

            case 2:
                printf("\nPlease select the type of calculation [1/2] :");
                printf("\n1.  AREA");
                printf("\n2.  PERIMETER");
                printf("\nEnter the type of calculation [1/2]: ");
                scanf("%d", &ch1);

                if (ch1 == 1){
                    printf("\n\n+++++++++++SQAURE AREA+++++++++++++");
                    printf("\nPlease enter the side (cm): ");
                    scanf("%f", &side);
                    area = side * side;
                    printf("\n+++++++++++Result of Calculation+++++++++++++");
                    printf("\nArea: %.2f", area);
                    printf("\n\nDo you want to continue (Y/N) : ");
                    scanf("%s", &choice);
                    if (choice == 'Y')
                        break;
                    else{
                        printf("\n\n+++++++++++EXITING++++++++++++++++++++\n\n");
                        return 0;
                    }
                }
                else if(ch1 == 2){
                    printf("\n\n+++++++++++SQUARE PERIMETER+++++++++++++");
                    printf("\nPlease enter the side (cm): ");
                    scanf("%f", &side);
                    perimeter = 4 * side;
                    printf("\n+++++++++Result of Calculation+++++++++++++");
                    printf("\nPerimeter: %.2f", perimeter);
                    printf("\n\nDo you want to continue (Y/N) : ");
                    scanf("%s", &choice);
                    if (choice == 'Y')
                        break;
                    else{
                        printf("\n\n+++++++++++EXITING++++++++++++++++++++\n\n");
                        return 0;
                    }

                }
                else{
                    printf("\n\n+++++++++++EXITING++++++++++++++++++++\n\n");
                    return 0;
                }
        }
    }while(ch == 1 || ch == 2);
}
